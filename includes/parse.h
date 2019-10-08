/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 12:37:02 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 15:51:24 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <SDL2/SDL_pixels.h>

# include "gui.h"
# include "types.h"
# include "coord.h"

typedef struct	s_parse_info
{
	char				*name;
	t_gui_type			type;
	t_coord				pos;
	t_coord				dim;
	char				*img;
	char				*color;
	char				*draw_method;
	char				*text;
	char				*text_color;
	float				text_size;
	char				*text_font;
	char				*text_draw_method;
	char				*onclick;
	short				layer;
	t_bool				clickable;
	t_bool				show;
	struct s_parse_info	*child;
	struct s_parse_info	*next;
}				t_parse_info;

t_parse_info	*new_parse_info(void);
void			del_parse_info(t_parse_info **parse_info);

#endif
