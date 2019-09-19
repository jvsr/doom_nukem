/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_gui_config.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:03:27 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/18 20:14:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "libft/ft_memory.h"
#include "libft/ft_string.h"

#include "lex.h"
#include "error.h"
#include "gui_config.h"

static void		add_token(t_token **tokens, t_token *new)
{
	static t_token	*last = NULL;

	if (last == NULL)
		*tokens = new;
	else
		last->next = new;
	last = new;
}

static t_token	*create_token(t_token_type type, const char *file,
								size_t *index, size_t content_size)
{
	t_token *token;

	token = (t_token*)ft_memalloc(sizeof(t_token));
	if (token == NULL)
		error_msg(strerror(errno), errno, "Failed to alloc Token");
	else
	{
		token->type = type;
		token->token = ft_strndup(&file[*index], content_size);
		token->next = NULL;
		*index += content_size;
	}
	return (token);
}

static void		check_newline(t_token **tokens, const char *file, size_t *index)
{
	t_token			*new;
	const size_t	content_size = 1;

	new = create_token(NEWLINE, file, index, content_size);
	add_token(tokens, new);
	// while (file[index] == ' ' || file[index] '\t')
	// 	check_indent()
}

static void		check_dash(t_token **tokens, const char *file, size_t *index)
{
	t_token			*new;
	const size_t	content_size = 1;

	new = create_token(DASH, file, index, content_size);
	add_token(tokens, new);
}

static t_token	*create_tokens(const char *file)
{
	size_t	index;
	t_token	*tokens;

	index = 0;
	tokens = NULL;
	while(file[index]) 
	{
		if (file[index] == '-')
			check_dash(&tokens, file, &index);
		if (file[index] == '\n')
			check_newline(&tokens, file, &index);
	}
	return (tokens);
}

t_token	*lex_gui_config(const int fd)
{
	int		ret;
	char	*file;
	t_token	*tokens;

	ft_readfile(fd, &file);
	if (file == NULL)
		error_msg(sterror(errno), errno, "Failed to read the gui config file");
	tokens = create_tokens(file);
	return (tokens);
}