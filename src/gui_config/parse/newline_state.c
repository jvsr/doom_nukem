/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newline_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:26:46 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 15:26:46 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

static void		parse_info_to_parent(t_parse_manager *manager, size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		if (manager->parse_info->parent == NULL)
		{
			if (get_next_token_type(manager->token->next) != EOC)
				error_state(manager);
		}
		else
			manager->parse_info = manager->parse_info->parent;
		i++;
	}
}

t_return_code	newline_name_state(t_parse_manager *manager)
{
	size_t				amount;
	const t_token_type	next_token_type = get_next_token_type(manager->token);

	if (manager->token->token_amount > 1)
		return (repeat);
	else if (next_token_type == INDENT)
		return (ok);
	else if (next_token_type == NODENT)
	{
		parse_info_to_parent(manager, 1);
		return (ok);
	}
	else if (next_token_type == DEDENT)
	{
		amount = manager->token->next->token_amount + 1;
		manager->token->next->token_amount = 1;
		parse_info_to_parent(manager, amount);
		return (ok);
	}
	else
		return (fail);
}

t_return_code	newline_attr_state(t_parse_manager *manager)
{
	size_t				amount;
	const t_token_type	next_token_type = get_next_token_type(manager->token);

	if (manager->token->token_amount > 1)
		return (repeat);
	else if (next_token_type == INDENT)
		return (fail);
	else if (next_token_type == NODENT)
		return (ok);
	else if (next_token_type == DEDENT)
	{
		amount = manager->token->next->token_amount;
		manager->token->next->token_amount = 1;
		parse_info_to_parent(manager, amount);
		return (ok);
	}
	else
		return (fail);
}
