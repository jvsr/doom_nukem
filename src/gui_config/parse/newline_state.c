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

static void		parse_info_to_parent(t_parse_info **parse_info, t_token **token,
										size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		if ((*parse_info)->parent == NULL)
		{
			if (get_next_token_type(&(*token)->next) != EOC)
				error_state(token, parse_info);
		}
		else
			(*parse_info) = (*parse_info)->parent;
		i++;
	}
}

t_return_code	newline_name_state(t_token **token, t_parse_info **parse_info)
{
	size_t				amount;
	const t_token_type	next_token_type = get_next_token_type(token);

	if ((*token)->token_amount > 1)
		return (repeat);
	else if (next_token_type == INDENT)
		return (ok);
	else if (next_token_type == NODENT)
	{
		parse_info_to_parent(parse_info, token, 1);
		return (ok);
	}
	else if (next_token_type == DEDENT)
	{
		amount = (*token)->next->token_amount + 1;
		(*token)->next->token_amount = 1;
		parse_info_to_parent(parse_info, token, amount);
		return (ok);
	}
	else
		return (fail);
}

t_return_code	newline_attr_state(t_token **token, t_parse_info **parse_info)
{
	size_t				amount;
	const t_token_type	next_token_type = get_next_token_type(token);

	if ((*token)->token_amount > 1)
		return (repeat);
	else if (next_token_type == INDENT)
		return (fail);
	else if (next_token_type == NODENT)
		return (ok);
	else if (next_token_type == DEDENT)
	{
		amount = (*token)->next->token_amount;
		(*token)->next->token_amount = 1;
		parse_info_to_parent(parse_info, token, amount);
		return (ok);
	}
	else
		return (fail);
}
