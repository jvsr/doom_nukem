/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:58:29 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	space_state(t_parse_manager *manager)
{
	if (check_next(manager->token, ID) == ok
	&& (get_attr(manager->token->next->token) != fail
	|| check_type(manager->token->next->token) != fail))
		return (ok);
	return (fail);
}
