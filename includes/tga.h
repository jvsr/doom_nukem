/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tga.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 15:49:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/17 16:23:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGA_H
# define TGA_H

# include <SDL2/SDL.h>
# include "libft/ft_bool.h"

# if defined __linux__ || defined __APPLE__
#  include <unistd.h>
# else
#  include <io.h>
# endif

typedef struct	s_tga
{
	unsigned char	id_len;
	unsigned char	clr_map_type;
	unsigned char	img_type;
	unsigned short	cm_pos;
	unsigned short	cm_len;
	unsigned short	cm_size;
}				t_tga;

typedef struct	s_img
{
	unsigned short	x_origin;
	unsigned short	y_origin;
	unsigned short	width;
	unsigned short	height;
	unsigned char	px_depth;
	unsigned int	*pixels;
	unsigned int	pitch;
}				t_img;

SDL_Surface		*open_tga_sdl(char *file_name);
void			create_image(const char *file_name, t_img *img);
char			reversebyte(char b);
void			str_to_img(t_img *img, t_tga *tga, unsigned char *str);
int				pixel_from_pos(unsigned char *str, size_t i, t_img *img);

#endif
