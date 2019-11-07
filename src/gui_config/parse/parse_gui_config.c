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

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"
#include "transition_table.h"
#include "error.h"

static void			next_token(t_token **token)
{
	t_token	*cur;

	cur = *token;
	if ((*token)->token_amount == 1
	|| (*token)->type == ID
	|| (*token)->type == NUM
	|| (*token)->type == PLAIN)
	{
		*token = cur->next;
		free(cur->token);
		free(cur);
	}
	else
		(*token)->token_amount -= 1;
}

static t_state_code	lookup_state(t_state_code curstate, t_return_code rc)
{
	size_t			i;
	const size_t	m_items = sizeof(g_transition_table) / sizeof(t_transition);

	i = 0;
	while (i < m_items)
	{
		if (g_transition_table[i].src_state == curstate
		&& g_transition_table[i].ret_code == rc)
			return (g_transition_table[i].dst_state);
		i++;
	}
	error_msg("Unkown state", 20,
	ft_strformat("Undefined transition from %d with rc: '%d'", curstate, rc));
	return (-1);
}

t_parse_info		*parse_gui_config(t_token *tokens)
{
	t_return_code	rc;
	t_state_code	cur_state;
	t_parse_manager	*manager;
	t_parse_info	*parse_info;
	t_return_code	(*state_fnc)(t_parse_manager *);

	cur_state = entry;
	manager = new_parse_manager(tokens);
	while (1)
	{
		state_fnc = g_state[cur_state];
		rc = state_fnc(manager);
		if (cur_state == end)
			break ;
		if (cur_state != entry)
			next_token(&manager->token);
		cur_state = lookup_state(cur_state, rc);
	}
	parse_info = manager->parse_info;
	free(manager);
	return (parse_info);
}
