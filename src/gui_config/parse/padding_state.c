/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:25:02 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 16:25:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	padding_state(t_parse_manager *manager)
{
	const t_token_type	next_token_type = get_next_token_type(manager->token);

	manager->line++;
	if (next_token_type == DASH)
		return (ok);
	if (next_token_type == EOC)
		return (eoc);
	return (fail);
}
