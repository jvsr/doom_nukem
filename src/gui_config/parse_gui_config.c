/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_gui_config.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 12:35:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/01 15:53:32 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"
#include "parse.h"

#include "error.h"

#include "libft/ft_str.h"
#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

int	entry_state(t_token*, t_parse_info**);
int	dash_state(t_token*, t_parse_info**);
int	space_state(t_token*, t_parse_info**);
int	id_state(t_token*, t_parse_info**);
int	colon_name_state(t_token*, t_parse_info**);
int	space_name_state(t_token*, t_parse_info**);
int	name_state(t_token*, t_parse_info**);
int	newline_state(t_token*, t_parse_info**);
int	error_state(t_token*, t_parse_info**);
int	exit_state(t_token*, t_parse_info**);

int (*state[])(t_token*, t_parse_info**) = {
	entry_state,	dash_state,			space_state,	id_state,
	colon_name_state,	space_name_state,	name_state,
	newline_state,	error_state,	exit_state
																	};
enum state_code {
	entry,			dash,				space,			id,
	colon_name,			space_name,			name,		
	newline,		error,			end
																	};
enum return_code {
	ok,		repeat,	fail,	special,	eof,	type,
											 						};

struct s_transition
{
	enum state_code src_state;
	enum return_code ret_code;
	enum state_code dst_state;
};

const struct s_transition transition_table[] = {
	{entry, ok, dash},
	{entry, fail, error},
	{dash, ok, space},
	{dash, fail, error},
	{space, ok, id},
	{space, fail, error},
	{id, type, colon_name},
	{id, fail, error},
	{colon_name, ok, space_name},
	{colon_name, fail, error},
	{space_name, ok, name},
	{space_name, fail, error},
	{name, ok, newline},
	{name, fail, error},
	{newline, fail, error},
};

void	next_token(t_token **token)
{
	if ((*token)->token_amount == 1
	|| (*token)->type == ID
	|| (*token)->type == NUM
	|| (*token)->type == PLAIN)
		*token = (*token)->next;
	else
		(*token)->token_amount -= 1;
}

void	set_type(t_parse_info **parse_info, t_gui_type type)
{
	(*parse_info)->type = type;
}

void	set_name(t_parse_info **parse_info, const char *name)
{
	(*parse_info)->name = ft_strdup(name);
}

int	entry_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	dash_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->next && token->next->type == SPACE)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	space_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->next && token->next->type == ID)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	id_state(t_token* token, t_parse_info **parse_info)
{
	enum return_code	rc;
	static t_bool		first = TRUE;

	if (token->next && token->next->type == COLON)
	{
		if (first == TRUE)
		{
			set_type(parse_info, PANEL);
			rc = type;
			first = FALSE;
		}
		else
			rc = ok;
	}
	else
		rc = fail;
	return (rc);
}

int	colon_name_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->next && token->next->type == SPACE)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	space_name_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->next
	&& (token->next->type == ID || token->next->type == PLAIN))
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	name_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code	rc;

	set_name(parse_info, token->token);
	if (token->next
	&& (token->next->type == LF || token->next->type == CRLF))
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	newline_state(t_token *token, t_parse_info **parse_info)
{
	enum return_code rc;

	(void)parse_info;
	(void)token;
	rc = fail;
	return (rc);
}

int	error_state(t_token* token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	error_msg("Failed to parse", 20,
		ft_strformat("Unrecognized token \"%s\" in parser", token->token));
	rc = fail;
	return (rc);
}

int	exit_state(t_token* token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	(void)token;
	rc = fail;
	return (rc);
}

int		lookup_state(enum state_code curstate, enum return_code rc) {
	size_t i;
	size_t max_items = sizeof(transition_table)/sizeof(transition_table[0]);

	i = 0;
	while(i < max_items) {
		if (transition_table[i].src_state == curstate
		&& transition_table[i].ret_code == rc)
			return (transition_table[i].dst_state);
		i++;
	}
	return(-1);
}

t_parse_info	*parse_gui_config(t_token *tokens, const char *state_name)
{
	enum return_code	rc;
	enum state_code		cur_state;
	t_parse_info		*parse_info;
	int					(* state_fun)(t_token*, t_parse_info**);

	// while (tokens) {
	// 	tokens = tokens->next;
	// }
	cur_state = entry;
	parse_info = new_parse_info();
	while(1) {
		ft_printf("curToken: |%s|\n", tokens->token);
		ft_printf("curState: |%d|\n", cur_state);
		state_fun = state[cur_state];
		rc = state_fun(tokens, &parse_info);
		if (cur_state == end)
			break ;
		if (cur_state != entry)
			next_token(&tokens);
		cur_state = lookup_state(cur_state, rc);
	}

	return(parse_info);
	(void)state_name;
}
