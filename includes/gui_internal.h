/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_internal.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 15:32:53 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/13 13:39:36 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_INTERNAL_H
# define GUI_INTERNAL_H

# include "gui.h"

# define TEXT_ALPHA_ROUND	0x30

void			del_text(t_text **text);
void			del_image(t_image **image);
void			del_panel(t_panel **panel);
void			del_button(t_button **button);
void			del_gview(t_gview **gview);
void			del_map_editor(t_map_editor **map_editor);
t_text			*new_text(t_gui *ui);
t_image			*new_image(void);
t_panel			*new_panel(void);
t_button		*new_button(t_gui *ui);
t_gview			*new_gview(void);
t_map_editor	*new_map_editor(void);
void			print_text(t_text *text);
void			print_image(t_image *image);
void			print_button(t_button *button);
void			print_panel(t_panel *panel, t_bool print_children);
void			add_to_children(t_transform **children, t_transform *child);
void			del_child(t_transform **children, const char *name);
void			*draw_elem(t_transform *elem, t_game *game);
void			draw_elements(t_transform *elem, t_game *game);
void			draw_image(SDL_Surface *dst, t_image *image);
void			draw_text(SDL_Surface *dst, t_text *text, SDL_Point abs_dim);
void			draw_button(SDL_Surface *dst, t_button *button,
					SDL_Point abs_dim);
void			draw_panel(t_panel *panel, t_game *game);
void			draw_gview(SDL_Surface *dst, t_game *game);
void			draw_map_editor(SDL_Surface *dst,
					t_game *game, t_transform *elem);
void			merge_elem(t_transform *elem);
SDL_Surface		*render_text(const char *str, TTF_Font *font, SDL_Color *color);
void			check_elem_duplicate(t_transform *root_children,
					t_transform *new);

#endif
