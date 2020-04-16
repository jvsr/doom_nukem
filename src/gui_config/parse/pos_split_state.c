/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pos_split_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:22:22 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:40 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	pos_comma_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	pos_space_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}
