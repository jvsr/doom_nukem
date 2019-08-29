/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:41:44 by ehollidg      ########   odam.nl         */
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

typedef enum	e_guielem
{
	BUTTON,
	TEXT,
	IMAGE,
	PANEL
}				t_guielem;

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
	t_transform			*parent;
	t_list				*children;
	void				*guielem;
	t_guielem			guitype;
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
}				t_guiinfo;

t_button	*buttontexturenew(const t_guiinfo *guiinfo, const char *text,
			const t_font *font, const SDL_Surface *texture);
t_button	*buttoncolournew(const t_guiinfo *guiinfo, const char *text, 
			const t_font *font, const unsigned int colour);
t_text		*textnew(const t_guiinfo *guiinfo, const char *text,
			const t_font *font);
t_image		*imagenew(const t_guiinfo *guiinfo, const SDL_Surface *texture);
t_image		*panelnew(const t_guiinfo *guiinfo);
void		buttondestroy(t_button *button, const t_bool destroychildren);
void		paneldestroy(t_panel *panel, const t_bool destroychildren);
void		textdestroy(t_text *text, const t_bool destroychildren);
void		imagedestroy(t_image *image, const t_bool destroychildren);
void		childrendestroy(t_list *children, const t_bool destroychildren);

#endif
