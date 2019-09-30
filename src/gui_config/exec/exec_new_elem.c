/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_new_elem.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:54:20 by pholster       #+#    #+#                */
/*   Updated: 2019/09/26 17:54:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "gui.h"

/*
** * typedef struct	s_parse_info
** * {
** * 	char				*name;
** * 	t_gui_type			type;
** * 	t_coord				pos;
** * 	t_coord				dim;
** * 	char				*img;
** * 	SDL_Color			color;
** * 	t_draw_method		draw_method;
** * 	char				*text;
** * 	SDL_Color			text_color;
** * 	float				text_size;
** * 	t_font_type			text_font;
** * 	t_draw_method		text_draw_method;
** * 	char				*onclick;
** * 	short				layer;
** * 	t_bool				clickable;
** * 	t_bool				show;
** * 	struct parse_info	*child;
** * 	struct parse_info	*next;
** * }				t_parse_info;
*/

t_transform	*exec_new_elem(t_gui *ui, t_parse_info *parse_info)
{
	t_transform	*elem;

	elem = new_elem(ui, parse_info->name, parse_info->type);
	return (elem);
}
