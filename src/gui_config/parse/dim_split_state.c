/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dim_split_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:26:42 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:04 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	dim_comma_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	dim_space_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}
