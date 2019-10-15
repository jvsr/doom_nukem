/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:47:13 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 14:47:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"
#include "parse.h"

t_token_type	get_next_token_type(t_token *token)
{
	if (token->token_amount == 1
	|| token->type == ID
	|| token->type == NUM
	|| token->type == PLAIN)
	{
		if (token->next)
			return (token->next->type);
		else
			return (EOC);
	}
	else
		return (token->type);
}
