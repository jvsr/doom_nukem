/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dim_state.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:24:09 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:24:09 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	colon_dim_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_dim_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}
