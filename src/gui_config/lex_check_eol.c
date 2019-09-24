/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_check_eol.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:37:19 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/19 17:38:35 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

static void	lex_check_crlf(t_token **tokens, const char *file, size_t *index)
{
	t_token		*new;
	size_t		token_amount;
	size_t		content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == '\r'
	&& file[*index + content_size + 1] == '\n')
	{
		token_amount++;
		content_size += 2;
	}
	new = lex_create_token(CRLF, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
	lex_check_indent(tokens, file, index);
}

static void	lex_check_cr(t_token **tokens, const char *file, size_t *index)
{
	t_token		*new;
	size_t		token_amount;
	size_t		content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == '\r')
	{
		token_amount++;
		content_size++;
	}
	new = lex_create_token(CR, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
}

static void	lex_check_lf(t_token **tokens, const char *file, size_t *index)
{
	t_token		*new;
	size_t		token_amount;
	size_t		content_size;

	token_amount = 0;
	content_size = 0;
	while (file[*index + content_size] == '\n'
	&& file[*index + content_size + 1] != '\r')
	{
		token_amount++;
		content_size++;
	}
	new = lex_create_token(CR, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
	lex_check_indent(tokens, file, index);
}

void		lex_check_eol(t_token **tokens, const char *file, size_t *index)
{
	if (file[*index] == '\r')
	{
		if (file[*index + 1] == '\n')
			lex_check_crlf(tokens, file, index);
		else
			lex_check_cr(tokens, file, index);
	}
	else
		lex_check_lf(tokens, file, index);
}