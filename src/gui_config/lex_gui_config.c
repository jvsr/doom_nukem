/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex_gui_config.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:03:27 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/16 16:13:08 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "libft/ft_memory.h"
#include "libft/ft_string.h"

#include "error.h"
#include "gui_config.h"

static int	calc_indent(const char *line, int *indent)
{
	size_t	i;
	t_bool	space;

	i = 0;
	space = FALSE;
	while (line[i] == ' ' || line[i] == '\t')
	{
		if (space == TRUE)
		{
			(*indent)++;
			space = FALSE;
		}
		else if (line[i] == ' ')
			space = TRUE;
		else if (line[i] == '\t')
			(*indent)++;
		i++;
	}
	if (space == TRUE)
		i--;
	return (i);
}

static void	add_token(t_token **start, const int indent,
						const size_t i, const char *line)
{
	t_token	*new;
	t_token	*save;

	save = *start;
	new = (t_token*)ft_memalloc(sizeof(t_token));
	if (new == NULL)
		error_msg(strerror(errno), errno);
	new->indent = indent;
	new->token = ft_strdup(&line[i]);
	new->next = NULL;
	if (*start == NULL)
		*start = new;
	else
	{
		while (save->next)
			save = save->next;
		save->next = new;
	}
}

t_token	*lex_gui_config(const int fd)
{
	int		ret;
	char	*line;
	int		indent;
	size_t	i;
	t_token	*tokens;

	line = NULL;
	tokens = NULL;
	ret = ft_getnextline(fd, &line);
	while (ret > 0)
	{
		indent = 0;
		i = calc_indent(line, &indent);
		if (indent == 0)
			break ;
		add_token(&tokens, indent, i, line);
		free(line);
		ret = ft_getnextline(fd, &line);
	}
	free(line);
	return (tokens);
}