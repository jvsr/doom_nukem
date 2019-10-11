/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:58:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 16:58:29 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	space_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, ID));
}
