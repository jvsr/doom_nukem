/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_gui_config.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:03:27 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 13:51:55 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_char.h"

#include "libft/ft_printf.h" //

#include "lex.h"
#include "error.h"
#include "gui_config.h"

static t_token	*create_tokens(const char *file)
{
	size_t	index;
	t_token	*tokens;

	index = 0;
	tokens = NULL;
	while(file[index])
	{
		if (file[index] == '-')
			lex_check_dash(&tokens, file, &index);
		else if (file[index] == '\n' || file[index] == '\r')
			lex_check_eol(&tokens, file, &index);
		else if (ft_isalnum(file[index]))
			lex_check_alnum(&tokens, file, &index);
		else if (file[index] == ' ')
			lex_check_space(&tokens, file, &index);
		else
			error_msg("Lexing error:", 19, "Unrecognized character");
	}
	return (tokens);
}

t_token	*lex_gui_config(const int fd)
{
	char	*file;
	t_token	*tokens;

	ft_readfile(fd, &file);
	if (file == NULL)
		error_msg(strerror(errno), errno, "Failed to read the gui config file");
	tokens = create_tokens(file);
	return (tokens);
}
