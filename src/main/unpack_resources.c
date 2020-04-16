/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unpack_resources.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:57:02 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:52:46 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "libft/ft_str.h"
#include "libft/ft_strarr.h"
#include "libft/ft_num.h"
#include "libft/ft_mem.h"

#include "game.h"
#include "error.h"
#include "init.h"
#include "audio.h"
#include "sdl_thread.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

char		*read_name(const int fd, off_t *offset, const char *prefix)
{
	char	buf[128];
	ssize_t	ret;
	char	*res;

	*offset += 128;
	lseek(fd, -(*offset), SEEK_END);
	ret = read(fd, buf, 128);
	if (ret == -1)
		error_msg_errno("Failed to unpack resources");
	res = ft_strdup(prefix);
	ft_strappend(&res, buf);
	if (res == NULL)
		error_msg_errno("Failed to allocate file name");
	return (res);
}

intmax_t	read_size(const int fd, off_t *offset)
{
	char		buf[24];
	intmax_t	res;
	ssize_t		ret;

	*offset += 24;
	lseek(fd, -(*offset), SEEK_END);
	ret = read(fd, buf, 24);
	if (ret == -1)
		error_msg_errno("Failed to unpack resources");
	res = ft_atoi(buf);
	return (res);
}

void		makedir_r(const char *name)
{
	size_t	i;
	char	path[PATH_MAX];
	char	**arr;

	i = 0;
	ft_memset(path, '\0', PATH_MAX);
	arr = ft_strsplit(name, '/');
	while (arr[i] && arr[i + 1])
	{
		ft_strcat(path, arr[i]);
		ft_strcat(path, "/");
		mkdir(path, 0770);
		i++;
	}
	ft_strarrdel(&arr);
}

void		read_file(const int fd, off_t *offset, const char *name,
						const intmax_t size)
{
	int		w_fd;
	int		ret;
	char	*buf;

	*offset += size;
	lseek(fd, -(*offset), SEEK_END);
	if (access(name, F_OK) == -1)
	{
		makedir_r(name);
		w_fd = open(name, (O_CREAT | O_WRONLY),
					(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP));
		buf = (char*)malloc(size);
		if (buf == NULL)
			error_msg_errno("Failed to allocate resource buf");
		ret = read(fd, buf, size);
		if (ret == -1)
			error_msg_errno("Failed to read resource");
		if (write(w_fd, buf, size) != size)
			error_msg_errno(ft_strformat("Failed to unpack '%s'", name));
		close(w_fd);
		free(buf);
	}
}

void		unpack_resources(t_game *game)
{
	char		*name;
	off_t		offset;
	intmax_t	size;
	const char	*path = ft_strjoin(game->exec_path, game->exec_name);
	const int	fd = open(path, O_RDONLY);

	offset = 0;
	while (TRUE)
	{
		name = read_name(fd, &offset, game->exec_path);
		if (ft_strequ(name, game->exec_path))
		{
			free(name);
			break ;
		}
		size = read_size(fd, &offset);
		read_file(fd, &offset, name, size);
		free(name);
	}
	close(fd);
	free((void*)path);
}
