/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dash_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:57:59 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 16:57:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	dash_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}
