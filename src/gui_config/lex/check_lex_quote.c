/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_lex_quote.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:33:49 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 14:34:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

static void	check_lex_dquote(t_token **tokens, const char *file, size_t *index)
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
	new = create_lex_token(DQUOTE, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
}

static void	check_lex_squote(t_token **tokens, const char *file, size_t *index)
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
	new = create_lex_token(SQUOTE, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
}

void		check_lex_quote(t_token **tokens, const char *file, size_t *index)
{
	if (file[*index] == '\"')
		check_lex_dquote(tokens, file, index);
	else
		check_lex_squote(tokens, file, index);
}
