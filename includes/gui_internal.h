/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_internal.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 15:32:53 by pholster       #+#    #+#                */
/*   Updated: 2019/10/16 15:32:53 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_INTERNAL_H
# define GUI_INTERNAL_H

# include "gui.h"

# define TEXT_ALPHA_ROUND	0x30
# define TEXT_RATIO_WIDTH	1280
# define TEXT_RATIO_HEIGHT	720

typedef struct	s_onclickpair
{
	const char	*name;
	t_onclick	*f;
}				t_onclickpair;

typedef struct	s_matchpair
{
	const char	*name;
	int			value;
}				t_matchpair;

void			del_text(t_text **text);
void			del_image(t_image **image);
void			del_panel(t_panel **panel);
void			del_button(t_button **button);
t_text			*new_text(t_gui *ui);
t_image			*new_image(void);
t_panel			*new_panel(void);
t_button		*new_button(t_gui *ui);
void			print_text(t_text *text);
void			print_image(t_image *image);
void			print_button(t_button *button);
void			print_panel(t_panel *panel, t_bool print_children);
void			add_to_children(t_transform **children, t_transform *child);
void			del_child(t_transform **children, const char *name);
void			draw_elem(t_transform *elem, t_gui *ui);
void			draw_image(SDL_Surface *dst, t_image *image);
void			draw_text(SDL_Surface *dst, t_text *text, t_gui *ui);
void			draw_button(SDL_Surface *dst, t_button *button, t_gui *ui);
void			draw_panel(t_panel *panel, t_gui *ui);
SDL_Surface		*render_text(const char *str, TTF_Font *font, SDL_Color *color);

#endif
