/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_check_hash.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:37:29 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/26 17:37:29 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

void	lex_check_hash(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == '#')
	{
		token_amount++;
		content_size++;
	}
	new = lex_create_token(HASH, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
}
