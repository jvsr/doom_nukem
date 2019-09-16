/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 18:26:42 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <SDL2/SDL_surface.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_ttf.h>

# include "libft/ft_bool.h"

# include "coord.h"

typedef struct s_game		t_game;
typedef struct s_gui		t_gui;
typedef struct s_text		t_text;
typedef struct s_image		t_image;
typedef struct s_button		t_button;
typedef struct s_panel		t_panel;

typedef enum	e_gui_type
{
	GUI_UNDFINED = -1,
	TEXT,
	IMAGE,
	BUTTON,
	PANEL
}				t_gui_type;

typedef enum	e_parent_type
{
	PARENT_UNDFINED = -1,
	GUI,
	ELEM
}				t_parent_type;

typedef	enum	e_font_type
{
	FONT_UNDFINED = -1,
	ROBOTO,
	MONOF,
	KARARC,
	FONT_AMOUNT
}				t_font_type;

typedef enum	e_draw_method
{
	SCALED,
	REPEAT,
	FIXED,
	CENTERED,
	COLOR
}				t_draw_method;

typedef	union	u_gui_elem
{
	t_text		*text;
	t_image		*image;
	t_button	*button;
	t_panel		*panel;
}				t_gui_elem;

typedef	union	u_parent
{
	t_gui		*ui;
	t_transform	*elem;
}				t_parent;

typedef struct	s_font
{
	t_font_type	type;
	float		size;
	SDL_Color	color;
}				t_font;

typedef struct	s_transform
{
	t_coord				pos;
	t_coord				dim;
	SDL_Point			abs_pos;
	SDL_Point			abs_dim;
	char				*name;
	t_bool				show;
	t_bool				clickable;
	short				layer;
	t_gui_type			gui_type;
	t_gui_elem			gui_elem;
	void				(*onclick)(t_game *, struct s_transform *);
	SDL_Surface			*surface;
	t_bool				redraw;
	t_parent_type		parent_type;
	t_parent			parent;
	struct s_transform	*next;
}				t_transform;

typedef struct	s_text
{
	char			*text;
	t_font			font;
}				t_text;

typedef struct	s_image
{
	t_draw_method	draw_method;
	SDL_Color		color;
	SDL_Surface		*texture;
}				t_image;

typedef struct	s_button
{
	char			*text;
	t_font			font;
	t_draw_method	draw_method;
	SDL_Color		color;
	SDL_Surface		*texture;
}				t_button;

typedef struct	s_panel
{
	t_transform		*children;
}				t_panel;

typedef struct	s_gui
{
	SDL_Surface	*window_surface;
	t_transform	*children;
	TTF_Font	*fonts[FONT_AMOUNT];
}				t_gui;

void			set_elem_clickable(t_transform *elem, t_bool clickable);
void			set_elem_show(t_transform *elem, t_bool show);
void			set_elem_pos(t_transform *elem, t_coord pos);
void			set_elem_dim(t_transform *elem, t_coord dim);
void			remove_elem_parent(t_transform *elem);
void			set_elem_layer(t_transform *elem, short layer);
void			set_elem_redraw(t_transform *elem);
void			del_elem(t_transform **elem);
void			del_button(t_button **button);
void			del_image(t_image **image);
void			del_panel(t_panel **panel);
void			del_text(t_text **text);
void			check_gui_hit(t_game *game, SDL_Point pos);
void			draw_elem(t_transform *elem);
void			draw_gui(t_gui *ui);
void			draw_image(t_transform *elem);
void			draw_text(t_transform *elem);
void			draw_button(t_transform *elem);
void			draw_panel(t_transform *elem);
TTF_Font		*get_font(TTF_Font **fonts, t_font_type font);
t_bool			is_elem_shown(t_transform *elem);
t_transform		*get_elem(t_transform *elem, const char *name);
t_text			*new_text(t_game *game);
t_image			*new_image(t_game *game);
t_button		*new_button(t_game *game);
t_panel			*new_panel(t_game *game);
void			add_elem_child(t_transform *parent, t_transform *child);
void			add_gui_child(t_gui *ui, t_transform *panel);
t_transform		*new_elem(t_game *game, const char *name, t_gui_type type);
void			add_to_children(t_transform **children, t_transform *child);

#endif
