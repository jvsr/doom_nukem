/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_lex_alnum.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:40:09 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 15:22:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/ft_char.h"

#include "lex.h"

static void	check_lex_plain(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (ft_isalnum(file[*index + content_size])
	|| file[*index + content_size] == '_'
	|| file[*index + content_size] == '/')
	{
		token_amount++;
		content_size++;
	}
	new = create_lex_token(PLAIN, token_amount);
	set_lex_token_value(new, file, index, content_size);
	add_lex_token(tokens, new);
}

static void	check_lex_id(t_token **tokens, const char *file, size_t *index)
{
	t_token	*new;
	size_t	token_amount;
	size_t	content_size;

	token_amount = 0;
	content_size = 0;
	while (ft_isalpha(file[*index + content_size])
	|| file[*index + content_size] == '_')
	{
		token_amount++;
		content_size++;
	}
	if (ft_isdigit(file[*index + content_size])
	|| file[*index + content_size] == '/')
		check_lex_plain(tokens, file, index);
	else
	{
		new = create_lex_token(ID, token_amount);
		set_lex_token_value(new, file, index, content_size);
		add_lex_token(tokens, new);
	}
}

static void	check_lex_num(t_token **tokens, const char *file, size_t *index)
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
	if (ft_isalpha(file[*index + content_size])
	|| file[*index + content_size] == '_'
	|| file[*index + content_size] == '/')
		check_lex_plain(tokens, file, index);
	else
	{
		new = create_lex_token(NUM, token_amount);
		set_lex_token_value(new, file, index, content_size);
		add_lex_token(tokens, new);
	}
}

void		check_lex_alnum(t_token **tokens, const char *file, size_t *index)
{
	if (ft_isalpha(file[*index]))
		check_lex_id(tokens, file, index);
	else
		check_lex_num(tokens, file, index);
}
