/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   entry_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:57:13 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:58 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_return_code	entry_state(t_parse_manager *manager)
{
	t_return_code	rc;

	if (manager->token->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}
