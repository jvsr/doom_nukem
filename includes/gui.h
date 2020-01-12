/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/07 20:27:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <SDL2/SDL_surface.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_ttf.h>

# include "libft/ft_bool.h"

# include "coord.h"

# define FONT_PATH "resources/fonts/"

typedef struct s_game		t_game;
typedef struct s_gui		t_gui;
typedef struct s_transform	t_transform;
typedef struct s_text		t_text;
typedef struct s_image		t_image;
typedef struct s_button		t_button;
typedef struct s_panel		t_panel;
typedef struct s_gview		t_gview;

typedef void	(t_onclick)(t_game *, t_transform *);

typedef enum	e_gui_type
{
	GUI_UNDEFINED = -1,
	TEXT,
	IMAGE,
	BUTTON,
	PANEL,
	GVIEW
}				t_gui_type;

typedef enum	e_parent_type
{
	PARENT_UNDEFINED = -1,
	GUI,
	ELEM
}				t_parent_type;

typedef	enum	e_font_type
{
	FONT_UNDEFINED = -1,
	ROBOTO,
	MONOF,
	KARARC,
	FOULFIEND,
	NECKROMANCER,
	FONT_AMOUNT
}				t_font_type;

typedef enum	e_draw_method
{
	DRAW_METHOD_UNDEFINED = -1,
	SCALED,
	REPEAT,
	FIXED,
	CENTERED,
	COLOR,
	DRAW_METHOD_AMOUNT
}				t_draw_method;

typedef	union	u_gui_elem
{
	t_text		*text;
	t_image		*image;
	t_button	*button;
	t_panel		*panel;
	t_gview		*gview;
}				t_gui_elem;

typedef	union	u_parent
{
	t_gui		*ui;
	t_transform	*elem;
}				t_parent;

struct			s_transform
{
	t_coord				pos;
	t_coord				dim;
	SDL_Point			rel_pos;
	SDL_Point			abs_pos;
	SDL_Point			abs_dim;
	char				*name;
	t_bool				show;
	short				layer;
	t_gui_type			gui_type;
	t_gui_elem			gui_elem;
	t_onclick			*onclick;
	void				*user_data;
	t_bool				clickable;
	t_bool				moved;
	t_bool				redraw;
	SDL_Surface			*surface;
	t_bool				has_alpha;
	t_parent_type		parent_type;
	t_parent			parent;
	struct s_transform	*next;
};

struct			s_text
{
	t_draw_method	draw_method;
	char			*text;
	float			size;
	SDL_Color		color;
	t_font_type		font_type;
	TTF_Font		**fonts;
};

struct			s_image
{
	t_draw_method	draw_method;
	SDL_Color		color;
	SDL_Surface		*texture;
};

struct			s_button
{
	t_text		*text;
	t_image		*image;
};

struct			s_panel
{
	t_transform	*children;
};

struct			s_gview
{

};

struct			s_gui
{
	SDL_Surface	*window_surface;
	t_transform	*children;
	TTF_Font	*fonts[FONT_AMOUNT];
	t_bool		redraw;
};

t_transform		*check_gui_hit(t_game *game, SDL_Point pos);
void			draw_gui(t_gui *ui, t_game *game);
void			print_elem(t_transform *elem, t_bool print_children);
t_transform		*new_elem(t_gui *ui, const char *name, t_gui_type type);
void			add_gui_child(t_gui *ui, t_transform *panel);
void			add_elem_child(t_transform *parent, t_transform *child);
void			remove_elem_parent(t_transform *elem);
void			set_elem_moved(t_transform *elem);
void			set_elem_redraw(t_transform *elem);
void			set_elem_pos(t_transform *elem, t_coord pos);
void			set_elem_dim(t_transform *elem, t_coord dim);
void			set_elem_show(t_transform *elem, t_bool show);
void			set_elem_show_clickable(t_transform *elem, t_bool show_click);
void			set_elem_layer(t_transform *elem, short layer);
void			set_elem_clickable(t_transform *elem, t_bool clickable);
void			set_elem_user_data(t_transform *elem, void *user_data);
void			set_elem_text_str(t_transform *elem, const char *str);
void			set_elem_text_size(t_transform *elem, float size);
void			set_elem_text_color(t_transform *elem, SDL_Color color);
void			set_elem_text_font(t_transform *elem, t_font_type font);
void			set_elem_text_draw_method(t_transform *elem,
											t_draw_method draw_method);
void			set_elem_image_texture(t_transform *elem, SDL_Surface *texture);
void			set_elem_image_color(t_transform *elem, SDL_Color color);
void			set_elem_image_draw_method(t_transform *elem,
											t_draw_method draw_method);
void			set_elem_onclick(t_transform *elem, t_onclick *onclick);
void			del_elem(t_transform **elem);
void			del_elem_child(t_transform *elem, const char *name);
void			del_gui_child(t_gui *ui, const char *name);
void			del_gui_children(t_gui *ui);
t_bool			get_elem_show(t_transform *elem);
TTF_Font		*get_font(TTF_Font **fonts, t_font_type font);
t_transform		*get_elem_child(t_transform *elem, const char *name);
t_transform		*get_gui_child(t_gui *ui, const char *name);
const char		*get_onclick_name(t_onclick *onclick);
t_onclick		*get_onclick_f(const char *name);
const char		*get_draw_method_name(t_draw_method draw_method);
t_draw_method	get_draw_method_value(const char *name);
const char		*get_font_type_name(t_font_type font_type);
t_font_type		get_font_type_value(const char *name);
const char		*get_gui_type_name(t_gui_type gui_type);
t_gui_type		get_gui_type_value(const char *name);

#endif
