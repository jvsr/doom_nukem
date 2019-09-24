/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_check_quote.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:33:49 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 14:34:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

static void	lex_check_dquote(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == '\"')
	{
		token_amount++;
		content_size++;
	}
	new = lex_create_token(DQUOTE, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
}

static void	lex_check_squote(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == '\'')
	{
		token_amount++;
		content_size++;
	}
	new = lex_create_token(SQUOTE, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);	
}

void	lex_check_quote(t_token **tokens, const char *file, size_t *index)
{
	if (file[*index] == '\"')
		lex_check_dquote(tokens, file, index);
	else
		lex_check_squote(tokens, file, index);
}
