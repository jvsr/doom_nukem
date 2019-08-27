/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/27 17:59:26 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

#include "libft/ft_bool.h"
#include "coord.h"
#include <SDL/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "draw.h"

typedef	enum	e_font
{
	arial
}				t_font;

typedef struct	s_transform
{
	char				*name;
	t_coord				position;
	t_bool				visible;
	struct s_transform	*parent;
	struct s_transform	**children;
}				t_transform;

typedef struct	s_text
{
	t_transform		transform;
	char			*text;
	t_font			font;
	float			fontsize;
}				t_text;

typedef struct	s_buttton
{
	t_transform		transform;
	char			*text;
	t_font			font;
	float			fontsize;
	t_coord			size;
	void			(*onclick)(t_game *, t_button *);
}				t_button;

typedef struct	s_image
{
	t_transform		transform;
	t_coord			size;
	SDL_Surface		*texture;
}				t_image;

typedef struct	s_panel
{
	t_transform		transform;
	t_coord			size;
}				t_panel;

#endif
