/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_gui_config.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 12:35:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 17:17:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"
#include "parse.h"

#include "error.h"

#include "libft/ft_str.h"
#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

int	entry_state(t_token*, t_parse_info*);
int	dash_state(t_token*, t_parse_info*);
int	space_state(t_token*, t_parse_info*);
int	id_state(t_token*, t_parse_info*);
int	first_id_state(t_token*, t_parse_info*);
int	colon_name_state(t_token*, t_parse_info*);
int	error_state(t_token*, t_parse_info*);
int	exit_state(t_token*, t_parse_info*);

int (*state[])(t_token*, t_parse_info*) = {
	entry_state,	dash_state,			space_state,	id_state,
	first_id_state,	colon_name_state,	error_state,	exit_state};
enum state_code {
	entry,			dash,				space,			id,
	first_id,		colon_name,			error,			end};

enum return_code { ok, repeat, fail, special, eof };

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
	{id, special, first_id},
	{id, fail, error},
	{first_id, ok, colon_name},
	{first_id, fail, error},
	{colon_name, fail, error},
};

t_parse_info	*start;

void	next_token(t_token **token)
{
	// ft_printf("tokenAmount: |%d|\n", (*token)->token_amount);
	if ((*token)->token_amount == 1 || (*token)->type == ID
	|| (*token)->type == NUM || (*token)->type == PLAIN)
		*token = (*token)->next;
	else
		(*token)->token_amount -= 1;
}

void	create_first_panel(void)
{
	parse_info = ft_memalloc(sizeof(t_parse_info));
	start = parse_info;
}

int	entry_state(t_token *token, t_parse_info *parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	dash_state(t_token *token, t_parse_info *parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->next && token->next->type == SPACE)
	{
		next_token(&token);
		rc = ok;
	}
	else
		rc = fail;
	return (rc);
}

int	space_state(t_token *token, t_parse_info *parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->type == ID)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	first_id_state(t_token *token, t_parse_info *parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	create_first_panel();
	if (token->type == COLON)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	id_state(t_token* token, t_parse_info *parse_info)
{
	enum return_code	rc;
	static t_bool		first = TRUE;

	(void)parse_info;
	if (first == TRUE)
	{
		rc = special;
		first = FALSE;
	}
	else if (token->type == COLON)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	colon_name_state(t_token *token, t_parse_info *parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if (token->type == SPACE)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	error_state(t_token* token, t_parse_info *parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	error_msg("Failed to parse", 20,
		ft_strformat("Unrecognized token \"%s\" in parser", token->token));
	rc = fail;
	return (rc);
}

int	exit_state(t_token* token, t_parse_info *parse_info)
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
    int					(* state_fun)(t_token*, t_parse_info*);

	// while (tokens) {
	// 	tokens = tokens->next;
	// }
	cur_state = entry;
	parse_info = NULL;
	while(1) {
		ft_printf("curToken: |%s|\n", tokens->token);
		ft_printf("curState: |%d|\n", cur_state);
		state_fun = state[cur_state];
		rc = state_fun(tokens, parse_info);
		if (cur_state == end)
			break ;
		cur_state = lookup_state(cur_state, rc);
	}

	return(parse_info);
	(void)state_name;
}
