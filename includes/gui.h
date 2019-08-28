/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:23:38 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

#include "libft/ft_bool.h"
#include "coord.h"
#include <SDL/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "libft/ft_list.h"
#include "game.h"

typedef	enum	e_fonttype
{
	arial
}				t_fonttype;

typedef struct s_font
{
	t_fonttype	font;
	float		size;
}				t_font;

typedef struct	s_transform
{
	char				*name;
	t_coord				position;
	t_bool				visible;
	struct s_transform	*parent;
	t_list				*children;
}				t_transform;

typedef struct	s_text
{
	t_transform		transform;
	char			*text;
	t_font			font;
}				t_text;

typedef struct	s_buttton
{
	t_transform		transform;
	char			*text;
	t_font			font;
	t_coord			size;
	SDL_Surface		*texture;
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

typedef struct	s_guiinfo
{
	char		*name;
	t_bool		visible;
	t_coord		position;
	t_coord		size;
	t_transform	*parent;
}				t_guiinfo;

t_button	*buttontexturenew(t_guiinfo *guiinfo, char *text, t_font *font, 
			SDL_Surface *texture);
t_button	*buttoncolournew(t_guiinfo *guiinfo, char *text, t_font *font, 
			unsigned int colour);
t_text		*textnew(t_guiinfo *guiinfo, char *text, t_font *font);
t_image		*imagenew(t_guiinfo *guiinfo, SDL_Surface *texture);
t_image		*panelnew(t_guiinfo *guiinfo);

#endif
