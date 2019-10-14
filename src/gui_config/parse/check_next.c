/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_next.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:22:27 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 14:22:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

t_return_code	check_next(t_token *token, t_token_type type)
{
	if (get_next_token_type(token) == type)
		return (ok);
	return (fail);
}

t_return_code	check_next_str(t_token *token)
{
	const t_token_type	type = get_next_token_type(token);

	if (type == ID || type == PLAIN)
		return (ok);
	return (fail);
}

t_return_code	check_next_hex(t_token *token)
{
	const t_token_type	type = get_next_token_type(token);

	if ((type == NUM || check_next_str(token) == ok)
	&& ft_strishex(token->next->token))
		return (ok);
	return (fail);
}

t_return_code	check_next_newline(t_token *token)
{
	const t_token_type	type = get_next_token_type(token);

	if (type == LF || type == CRLF)
		return (ok);
	return (fail);
}
