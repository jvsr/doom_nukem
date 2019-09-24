/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_set_token_value.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 16:16:50 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/19 18:17:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_str.h"

#include "lex.h"

void	lex_set_token_value(t_token *token, const char *const file,
							size_t *const index, const size_t content_size)
{
	token->token = ft_strndup(&file[*index], content_size);
	*index += content_size;
}
