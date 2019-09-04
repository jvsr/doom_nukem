/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opentga.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 16:13:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 15:34:54 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tga.h"
#include <fcntl.h>
#include "libft/ft_string.h"

static void	settgaheader(unsigned char *str, t_tga *tga, t_img *img)
{
	tga->idlen = (str[0]);
	tga->clr_map_type = (str[1]);
	tga->img_type = (str[2]);
	tga->cmpos = (str[4] << 8) | str[3];
	tga->cmlen = (str[6] << 8) | str[5];
	tga->cmsize = str[7];
	img->xorigin = (str[9] << 8) | str[8];
	img->yorigin = (str[11] << 8) | str[10];
	img->width = (str[13] << 8) | str[12];
	img->height = (str[15] << 8) | str[14];
	img->pxdepth = str[16];
}

int			opentga(t_img *img, char *loc)
{
	int		fd;
	unsigned char	*str;
	t_tga	tga;

	fd = open(loc, O_RDONLY);
	if (fd == -1)
		return (0);
	ft_readfile(fd, (char**)&str);
	close(fd);
	if (str == NULL)
		return (0);
	settgaheader(str, &tga, img);
	if (tga.img_type == 0)
		return (0);
	strtoimg(img, &tga, str);
	return (1);
}
