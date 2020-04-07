/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_gui_config.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:03:27 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:44:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_char.h"

#include "lex.h"
#include "error.h"
#include "gui_config.h"

static void		create_token(const char *file, t_token **tokens, size_t *index)
{
	if (file[*index] == '-')
		check_lex_dash(tokens, file, index);
	else if (file[*index] == '\n' || file[*index] == '\r')
		check_lex_eol(tokens, file, index);
	else if (ft_isalnum(file[*index]))
		check_lex_alnum(tokens, file, index);
	else if (file[*index] == ' ')
		check_lex_space(tokens, file, index);
	else if (file[*index] == ':')
		check_lex_colon(tokens, file, index);
	else if (file[*index] == '#')
		check_lex_hash(tokens, file, index);
	else if (file[*index] == ',')
		check_lex_comma(tokens, file, index);
	else if (file[*index] == '.')
		check_lex_period(tokens, file, index);
	else if (file[*index] == '\"' || file[*index] == '\'')
		check_lex_quote(tokens, file, index);
	else
		error_msg("Lexing error:", 19,
			ft_strformat("Unrecognized character '%c'", file[*index]));
}

static t_token	*create_tokens(const char *file)
{
	size_t	index;
	t_token	*tokens;

	index = 0;
	tokens = NULL;
	while (file[index])
		create_token(file, &tokens, &index);
	add_lex_token(&tokens, NULL);
	return (tokens);
}

t_token			*lex_gui_config(const int fd)
{
	char	*file;
	t_token	*tokens;

	ft_readfile(fd, &file);
	if (file == NULL)
		error_msg(strerror(errno), errno, "Failed to read the gui config file");
	tokens = create_tokens(file);
	free(file);
	return (tokens);
}
