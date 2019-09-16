/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_gui_config.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:01:33 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/16 16:07:38 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <limits.h>

#include "libft/ft_string.h"

#include "error.h"

int	open_gui_config(const char *file_name)
{
	int		fd;
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, "./resources/ui/config/");
	ft_strcat(full_path, file_name);
	ft_strcat(full_path, ".ui.yml");
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		error_msg(strerror(errno), errno);
	return (fd);
}
