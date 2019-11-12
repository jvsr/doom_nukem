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

#include "tga.h"
#include "game.h"
#include "types.h"
#include "error.h"

static t_uint8	*read_tga_file(const char *file_name)
{
	int		fd;
	char	full_path[PATH_MAX];
	t_uint8	*file_stream;

	ft_strcpy(full_path, g_doom_dir);
	ft_strcat(full_path, TEXTURE_PATH);
	ft_strcat(full_path, file_name);
	ft_strcat(full_path, ".tga");
	fd = open(full_path, O_RDONLY);
	if (fd == -1)
		error_msg_errno(ft_strformat("Failed to open %s", full_path));
	ft_readfile(fd, (char**)&file_stream);
	if (file_stream == NULL)
		error_msg_errno(ft_strformat("Failed to read %s", full_path));
	close(fd);
	return (file_stream);
}

static void		set_tga_header(t_uint8 *file_stream, t_tga *tga, t_img *img)
{
	tga->id_len = file_stream[0];
	tga->clr_map_type = file_stream[1];
	tga->img_type = file_stream[2];
	tga->cm_pos = (file_stream[4] << 8) | file_stream[3];
	tga->cm_len = (file_stream[6] << 8) | file_stream[5];
	tga->cm_size = file_stream[7];
	img->x_origin = (file_stream[9] << 8) | file_stream[8];
	img->y_origin = (file_stream[11] << 8) | file_stream[10];
	img->width = (file_stream[13] << 8) | file_stream[12];
	img->height = (file_stream[15] << 8) | file_stream[14];
	img->px_depth = file_stream[16];
	img->origin = file_stream[17];
	img->pitch = img->width * (img->px_depth / 8);
}

void			create_image(const char *file_name, t_img *img)
{
	t_tga	tga;
	t_uint8	*file_stream;

	file_stream = read_tga_file(file_name);
	set_tga_header(file_stream, &tga, img);
	if (tga.img_type == 0)
	{
		ft_strdel((char**)&file_stream);
		error_msg("Invalid tga format", EPERM, "Failed to read file");
	}
	str_to_img(img, &tga, file_stream);
	ft_strdel((char**)&file_stream);
}
