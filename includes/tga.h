/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tga.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 15:49:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 15:25:19 by ehollidg      ########   odam.nl         */
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
	unsigned char	idlen;
	unsigned char	clr_map_type;
	unsigned char	img_type;
	unsigned short	cmpos;
	unsigned short	cmlen;
	unsigned short	cmsize;
}				t_tga;

typedef struct	s_img
{
	unsigned char	pxdepth;
	unsigned short	xorigin;
	unsigned short	yorigin;
	unsigned short	width;
	unsigned short	height;
	unsigned int	*pixels;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_pt;
	void	*img_add;
	t_img	image;
}				t_mlx;

t_bool			opentga(t_img *img, char *loc);
char			reversebyte(char b);
void			strtoimg(t_img *img, t_tga *tga, unsigned char *str);
int				pixelfrompos(unsigned char *str, size_t i, t_img *img);
SDL_Surface		*tgaopenassdl(char *loc);

#endif
