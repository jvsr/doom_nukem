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

# include <limits.h>

# include <SDL2/SDL_pixels.h>

# include "gui.h"
# include "types.h"
# include "coord.h"

typedef struct	s_parse_info
{
	char				*name; //done
	t_gui_type			type; //done
	t_coord				pos; //done
	t_coord				dim; //done
	char				texture[PATH_MAX]; //done
	char				*color; //done
	char				*draw_method; //done
	char				*text; //done
	char				*text_color; //done
	float				text_size; //done
	char				*text_font; //done
	char				*text_draw_method; //done
	char				*onclick; //done
	short				layer; //done
	t_bool				clickable; //done
	t_bool				show; //done
	struct s_parse_info	*child;
	struct s_parse_info	*next;
	struct s_parse_info	*parent;
}				t_parse_info;

t_parse_info	*new_parse_info(void
	);
void			del_parse_info(t_parse_info **parse_info);

#endif
