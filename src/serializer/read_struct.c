/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 14:25:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 14:25:37 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#include "libft/ft_str.h"
#include "libft/ft_bool.h"
#include "libft/ft_str.h"

#include "game.h"
#include "serializer.h"
#include "error.h"

unsigned char		*read_struct(const char *loc)
{
	int				fd;
	unsigned char	*file_stream;
	char			full_path[PATH_MAX];

	ft_strcpy(full_path, g_doom_dir);
	ft_strcat(full_path, RESOURCE_PATH);
	ft_strcat(full_path, loc);
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s", full_path));
	ft_readfile(fd, (char**)&file_stream);
	if (file_stream == NULL)
		error_msg_errno(ft_strformat("Failed to read %s", full_path));
	close(fd);
	return (file_stream);
}
