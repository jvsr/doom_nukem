/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entry_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:57:13 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 16:57:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	entry_state(t_token **token, t_parse_info **parse_info)
{
	t_return_code	rc;

	(void)parse_info;
	if ((*token)->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}
