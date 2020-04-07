/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_lex_token_value.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 16:16:50 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "lex.h"
#include "error.h"

void	set_lex_token_value(t_token *token, const char *const file,
							size_t *const index, const size_t content_size)
{
	token->token = ft_strndup(&file[*index], content_size);
	if (token->token == NULL)
		error_msg_errno("Failed to alloc Token");
	*index += content_size;
}
