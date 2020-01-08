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

#include "libft/ft_bool.h"
#include "libft/ft_str.h"

#include "game.h"
#include "serializer.h"
#include "error.h"

unsigned char		*read_struct(const char *loc, char const *exec_path)
{
	int				fd;
	unsigned char	*file_stream;
	char			full_path[PATH_MAX];

	if (exec_path != NULL)
		ft_strcpy(full_path, exec_path);
	else
		full_path[0] = '\0';
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
