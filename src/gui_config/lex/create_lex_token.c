/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_lex_token.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:33:52 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:30 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "libft/ft_str.h"
#include "libft/ft_mem.h"

#include "lex.h"
#include "error.h"

t_token	*create_lex_token(t_token_type type, const size_t token_amount)
{
	t_token *token;

	token = (t_token*)ft_memalloc(sizeof(t_token));
	if (token == NULL)
		error_msg(strerror(errno), errno, "Failed to alloc Token");
	else
	{
		token->type = type;
		token->token_amount = token_amount;
		token->next = NULL;
	}
	return (token);
}
