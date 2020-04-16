/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_lex_hash.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:37:29 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:35 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

void	check_lex_hash(t_token **tokens, const char *file, size_t *index)
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
	new = create_lex_token(HASH, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
}
