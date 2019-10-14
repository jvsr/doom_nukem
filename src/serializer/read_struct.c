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
#include "libft/ft_printf.h"
#include "libft/ft_bool.h"
#include "libft/ft_str.h"
#include "serializer.h"
#include "error.h"

unsigned char		*read_struct(const char *loc)
{
	int				fd;
	unsigned char	*file_stream;

	fd = open(loc, O_RDONLY);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s", loc));
	ft_readfile(fd, (char**)&file_stream);
	if (file_stream == NULL)
		error_msg_errno(ft_strformat("Failed to read %s", loc));
	close(fd);
	return (file_stream);
}
