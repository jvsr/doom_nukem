/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_check_alnum.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:40:09 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 13:42:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_char.h"

#include "lex.h"

static void	lex_check_plain(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (ft_isalnum(file[*index + content_size]))
	{
		token_amount++;
		content_size++;
	}
	new = lex_create_token(PLAIN, token_amount);
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
}

static void	lex_check_id(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (ft_isalpha(file[*index + content_size]))
	{
		token_amount++;
		content_size++;
	}
	if (ft_isdigit(file[*index + content_size]))
		lex_check_plain(tokens, file, index);
	else
	{
		new = lex_create_token(ID, token_amount);
		lex_set_token_value(new, file, index, content_size);
		lex_add_token(tokens, new);
	}
}

static void	lex_check_num(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (ft_isdigit(file[*index + content_size]))
	{
		token_amount++;
		content_size++;
	}
	if (ft_isalpha(file[*index + content_size]))
		lex_check_plain(tokens, file, index);
	else
	{
		new = lex_create_token(NUM, token_amount);
		lex_set_token_value(new, file, index, content_size);
		lex_add_token(tokens, new);
	}
}

void	lex_check_alnum(t_token **tokens, const char *file, size_t *index)
{
	if (ft_isalpha(file[*index]))
		lex_check_id(tokens, file, index);
	else
		lex_check_num(tokens, file, index);
}
