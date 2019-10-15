/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_struct.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 11:13:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 11:13:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "libft/ft_bool.h"
#include "libft/ft_printf.h"
#include "libft/ft_str.h"
#include "serializer.h"
#include "error.h"

t_bool	write_struct(char *loc, t_binary *bin)
{
	int		fd;
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, INIT_PATH);
	ft_strcat(full_path, loc);
	fd = open(full_path, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s", full_path));
	if (write(fd, bin->content, bin->c_size) == -1)
		error_msg_errno(ft_strformat("Failed to write to %s", full_path));
	close(fd);
	return (TRUE);
}
