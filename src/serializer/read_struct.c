/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 14:25:37 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 18:17:42 by euan          ########   odam.nl         */
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

unsigned char		*read_struct(const char *loc,
									char const *exec_path, size_t *file_size)
{
	int				fd;
	unsigned char	*file_stream;
	char			full_path[PATH_MAX];
	ssize_t			size;

	ft_strcpy(full_path, exec_path);
	ft_strcat(full_path, RESOURCE_PATH);
	ft_strcat(full_path, loc);
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s", full_path));
	size = ft_readfile(fd, (char**)&file_stream);
	if (file_stream == NULL)
		error_msg_errno(ft_strformat("Failed to read %s", full_path));
	*file_size = size;
	close(fd);
	return (file_stream);
}
