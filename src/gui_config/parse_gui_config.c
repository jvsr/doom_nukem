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
#include "libft/ft_printf.h"

int	entry_state(t_token*);
int	dash_state(t_token*);
int	space_state(t_token*);
int	id_state(t_token*);
int	error_state(t_token*);
int	exit_state(t_token*);

int (*state[])(t_token*) = { entry_state, dash_state, space_state, id_state, error_state, exit_state};
enum state_code { entry, dash, space, id, error, end };
enum return_code { ok, repeat, fail, eol };

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
};

#include <stdio.h>

void	next_token(t_token **token) {
	if ((*token)->token_amount == 1)
		*token = (*token)->next;
	else
		(*token)->token_amount -= 1;
}

int	entry_state(t_token* token) {
	enum return_code	rc;

	if (token->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
};
int	dash_state(t_token* token) {
	enum return_code	rc;

	if (token->type == SPACE)
		rc = ok;
	else
		rc = fail;
	return (rc);
};
int	space_state(t_token* token) {
	enum return_code	rc;

	if (token->type == ID)
		rc = ok;
	else
		rc = fail;
	return (rc);
};
int	id_state(t_token* token) {
	enum return_code	rc;

	if (token->type == ID)
		rc = ok;
	else
		rc = fail;
	return (rc);
};
int	error_state(t_token* token) {
	enum return_code	rc;

	error_msg("Failed to parse", 20,
		ft_strformat("Unrecognized token \"%s\" in parser", token->token));
	rc = fail;
	return (rc);
};
int	exit_state(t_token* token) {
	enum return_code	rc;

	(void)token;
	rc = fail;
	return (rc);
};

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

void	parse_gui_config(t_token *tokens, const char *state_name)
{
    enum state_code cur_state = entry;
    enum return_code rc;
    int (* state_fun)(t_token*);

	while(1) {
		// ft_printf("%d: ", tokens->token_amount);
		// ft_printf("%s\n", tokens->token);
		state_fun = state[cur_state];
		rc = state_fun(tokens);
		if (cur_state == end)
			break ;
		cur_state = lookup_state(cur_state, rc);
		if (cur_state != error)
			next_token(&tokens);
	}

	(void)state_name;
}
