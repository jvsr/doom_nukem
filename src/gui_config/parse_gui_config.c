/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_gui_config.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 17:45:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/16 16:10:03 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "libft/ft_string.h"

#include "gui.h"
#include "error.h"
#include "gui_config.h"

static void	set_state_gui_config(const int fd, const char *state_name)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = ft_getnextline(fd, &line);
	while (ret > 0 && ft_strequ(line, state_name) == FALSE)
	{
		free(line);
		ret = ft_getnextline(fd, &line);
	}
	if (ret == -1)
		error_msg(strerror(errno), errno);
	else if (ret == 0)
		error_msg("Could not find corresponding gui state", 1);
	free(line);
}

t_panel		*parse_gui_config(const char *state_name, const char *file_name)
{
	t_panel		*result;
	t_token		*tokens;
	const int	fd = open_gui_config(file_name);

	result = NULL;
	set_state_gui_config(fd, state_name);
	tokens = lex_gui_config(fd);
	close(fd);
	return (result);
}
