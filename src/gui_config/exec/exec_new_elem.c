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

#include "libft/ft_str.h"

#include "exec.h"
#include "parse.h"

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

const t_onclickpair	g_onclicks[] = {
	{"button_menu_missions", NULL},
	{"button_menu_options", NULL},
	{"button_menu_quit", NULL},
};

static t_onclick	*get_onclick(char *onclick)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(onclick, g_onclicks[i].name))
			return (g_onclicks[i].f);
		i++;
	}
	return (NULL);
}

t_transform			*exec_new_elem(t_gui *ui, t_parse_info *parse_info)
{
	t_transform	*elem;

	elem = new_elem(ui, parse_info->name, parse_info->type);
	set_elem_pos(elem, parse_info->pos);
	set_elem_dim(elem, parse_info->dim);
	set_elem_onclick(elem, get_onclick(parse_info->onclick));
	set_elem_layer(elem, parse_info->layer);
	set_elem_clickable(elem, parse_info->clickable);
	set_elem_show(elem, parse_info->show);
	return (elem);
}
