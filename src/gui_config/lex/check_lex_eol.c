/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_lex_eol.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:37:19 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/19 17:38:35 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

static void	check_lex_crlf(t_token **tokens, const char *file, size_t *index)
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
	new = create_lex_token(CRLF, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
	check_lex_indent(tokens, file, index);
}

static void	check_lex_cr(t_token **tokens, const char *file, size_t *index)
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
	new = create_lex_token(CR, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
}

static void	check_lex_lf(t_token **tokens, const char *file, size_t *index)
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
	new = create_lex_token(LF, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
	check_lex_indent(tokens, file, index);
}

void		check_lex_eol(t_token **tokens, const char *file, size_t *index)
{
	if (file[*index] == '\r')
	{
		if (file[*index + 1] == '\n')
			check_lex_crlf(tokens, file, index);
		else
			check_lex_cr(tokens, file, index);
	}
	else
		check_lex_lf(tokens, file, index);
}
