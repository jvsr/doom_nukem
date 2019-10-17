/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 16:13:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 17:18:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <limits.h>

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include "tga.h"
#include "error.h"

static int	open_tga_file(const char *file_name)
{
	int		fd;
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, TEXTURE_PATH);
	ft_strcat(full_path, file_name);
	ft_strcat(full_path, ".tga");
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s%s.tga",
			TEXTURE_PATH, file_name));
	return (fd);
}

static void	set_tga_header(unsigned char *str, t_tga *tga, t_img *img)
{
	tga->id_len = str[0];
	tga->clr_map_type = str[1];
	tga->img_type = str[2];
	tga->cm_pos = (str[4] << 8) | str[3];
	tga->cm_len = (str[6] << 8) | str[5];
	tga->cm_size = str[7];
	img->x_origin = (str[9] << 8) | str[8];
	img->y_origin = (str[11] << 8) | str[10];
	img->width = (str[13] << 8) | str[12];
	img->height = (str[15] << 8) | str[14];
	img->px_depth = str[16];
	img->origin = str[17];
	img->pitch = img->width * sizeof(unsigned int);
}

void		create_image(const char *file_name, t_img *img)
{
	int				fd;
	t_tga			tga;
	unsigned char	*file_stream;

	fd = open_tga_file(file_name);
	ft_readfile(fd, (char**)&file_stream);
	if (file_stream == NULL)
		error_msg_errno(ft_strformat("Failed to read %s%s.tga",
			TEXTURE_PATH, file_name));
	close(fd);
	set_tga_header(file_stream, &tga, img);
	if (tga.img_type == 0)
	{
		ft_strdel((char**)&file_stream);
		error_msg("Invalid tga format", EPERM, "Failed to read file");
	}
	str_to_img(img, &tga, file_stream);
	ft_strdel((char**)&file_stream);
}
