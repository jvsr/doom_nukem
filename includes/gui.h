/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 15:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 14:30:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <SDL2/SDL_surface.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_ttf.h>
# include "libft/ft_bool.h"
# include "coord.h"

# define GUI_NAME "gui"

typedef struct s_game		t_game;
typedef struct s_list		t_list;

typedef	enum	e_fonttype
{
	ROBOTO,
	MONOF,
	KARARC,
	FONT_AMOUNT
}				t_fonttype;

typedef enum	e_guielem
{
	BUTTON,
	TEXT,
	IMAGE,
	PANEL
}				t_guielem;

typedef struct	s_font
{
	t_fonttype	font;
	float		size;
	SDL_Color	colour;
}				t_font;

typedef struct	s_transform
{
	t_coord				position;
	char				*name;
	t_bool				visible;
	short				layer;
	struct s_transform	*parent;
	t_list				*children;
	t_guielem			guitype;
	void				*guielem;
	void				(*onclick)(t_game *, struct s_transform *);
	struct s_transform	*next;
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
	SDL_Surface		*panel;
	t_coord			size;
}				t_panel;

typedef struct	s_gui
{
	t_transform	transform;
	t_bool		redraw;
	SDL_Surface	*guisurface;
	TTF_Font	*font[FONT_AMOUNT];
	t_list		*onclicks;
}				t_gui;

typedef struct	s_guiinfo
{
	char		*name;
	t_bool		visible;
	t_coord		position;
	t_coord		size;
}				t_guiinfo;

void			addtransformclick(t_gui *ui, t_transform *transform,
								void (*onclick)(t_game *, t_transform *));
void			checkclick(t_game *game, SDL_Point mpos);
void			destroybutton(t_gui *ui, t_button **button,
												const t_bool delchildren);
void			destroypanel(t_gui *ui, t_panel **panel,
							const t_bool delchildren);
void			destroytext(t_gui *ui, t_text **text,
							const t_bool delchildren);
void			destroyimage(t_gui *ui, t_image **image,
							const t_bool delchildren);
void			destroychildren(t_gui *ui, t_list *children,
							const t_bool delchildren);
void			destroyclick(t_gui *ui, char *name);
void			drawelem(t_gui *ui, t_transform *elem);
void			drawgui(t_game *game);
void			drawtext(t_gui *ui, t_text *text);
void			drawimage(t_gui *ui, t_image *image);
void			drawbutton(t_gui *ui, t_button *button);
void			drawpanel(t_gui *ui, t_panel *panel);
TTF_Font		*getfont(t_gui *ui, t_fonttype font);
SDL_Surface		*gettextsurface(t_gui *ui, char *text, t_font fonttype);
t_bool			gettransformvisible(t_transform *transform);
t_transform		*gettransformbyname(t_gui *ui, char *name);
t_transform		*gettransforminchildren(t_transform *trans, char *name);
t_button		*newbuttontexture(t_guiinfo *guiinfo, char *text,
					t_font *font, const SDL_Surface *texture);
t_button		*newbuttoncolour(t_guiinfo *guiinfo, char *text,
					t_font *font, const SDL_Color colour);
t_text			*newtext(t_guiinfo *guiinfo, char *text, t_font *font);
t_image			*newimage(t_guiinfo *guiinfo, const SDL_Surface *texture);
t_image			*newimagecolour(t_guiinfo *guiinfo, SDL_Color colour);
t_panel			*newpanel(t_guiinfo *guiinfo);
void			settransformparent(t_transform *child, t_transform *parent);
void			destroytransformclick(t_gui *ui, t_transform *transform);

#endif
