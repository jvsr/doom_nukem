/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_check_indent.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:18:41 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/19 18:32:29 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"

static void	calculate_amount_size(const char *file, const size_t *index,
									size_t *token_amount, size_t *content_size)
{
	while (file[*index + *content_size] == ' '
	|| file[*index + *content_size] == '\t')
	{
		if (file[*index + *content_size] == ' '
		&& (file[*index + *content_size + 1] == ' '
		|| file[*index + *content_size + 1] == '\t'))
		{
			*token_amount += 1;
			*content_size += 2;
		}
		else if (file[*index + *content_size] == '\t')
		{
			*token_amount += 1;
			*content_size += 1;
		}
		else
			return ;
	}
}
void	lex_check_indent(t_token **tokens, const char *const file,
							size_t *const index)
{
	t_token			*new;
	size_t			token_amount;
	size_t			content_size;
	static size_t	previous_indent = 0;

	token_amount = 0;
	content_size = 0;
	calculate_amount_size(file, index, &token_amount, &content_size);
	if (token_amount > previous_indent)
		new = lex_create_token(INDENT, token_amount - previous_indent);
	else if (token_amount < previous_indent)
		new = lex_create_token(DEDENT, previous_indent - token_amount);
	else
		new = lex_create_token(NODENT, 0);
	previous_indent = token_amount;
	lex_set_token_value(new, file, index, content_size);
	lex_add_token(tokens, new);
}
