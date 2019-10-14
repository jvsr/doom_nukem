/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_lex_colon.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:33:49 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 14:10:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

void	check_lex_colon(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == ':')
	{
		token_amount++;
		content_size++;
	}
	new = create_lex_token(COLON, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
}
