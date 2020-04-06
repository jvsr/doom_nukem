/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 12:37:02 by jvisser       #+#    #+#                 */
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

typedef	struct s_token		t_token;
typedef	enum e_token_type	t_token_type;

typedef enum	e_return_code
{
	fail,
	ok,
	repeat,
	type,
	pos,
	onclick,
	texture,
	clickable,
	color,
	layer,
	show,
	dim,
	draw_method,
	text,
	min,
	text_size,
	text_color,
	text_font,
	text_draw_method,
	eoc,
}				t_return_code;

typedef struct	s_parse_info
{
	char				*name;
	t_gui_type			type;
	t_coord				pos;
	t_coord				dim;
	char				texture[PATH_MAX];
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
	struct s_parse_info	*parent;
}				t_parse_info;

typedef struct	s_parse_manager
{
	size_t			line;
	t_token			*token;
	t_parse_info	*parse_info;
}				t_parse_manager;

t_parse_info	*new_parse_info(void);
void			del_parse_info(t_parse_info **parse_info);
t_parse_manager	*new_parse_manager(t_token *token);

t_return_code	get_attr(const char *attr);
t_token_type	get_next_token_type(t_token *token);

t_return_code	check_type(const char *type);
t_return_code	check_next(t_token *token, t_token_type type);
t_return_code	check_next_str(t_token *token);
t_return_code	check_next_hex(t_token *token);
t_return_code	check_next_newline(t_token *token);

/*
**	* === === === === === STATE PROTOTYPES === === === === === *
*/

t_return_code	entry_state(t_parse_manager *manager);

t_return_code	dash_state(t_parse_manager *manager);
t_return_code	space_state(t_parse_manager *manager);

t_return_code	newline_name_state(t_parse_manager *manager);
t_return_code	newline_attr_state(t_parse_manager *manager);

t_return_code	padding_state(t_parse_manager *manager);

t_return_code	id_state(t_parse_manager *manager);

t_return_code	colon_name_state(t_parse_manager *manager);
t_return_code	space_name_state(t_parse_manager *manager);
t_return_code	name_state(t_parse_manager *manager);

t_return_code	colon_color_state(t_parse_manager *manager);
t_return_code	space_color_state(t_parse_manager *manager);
t_return_code	hash_color_state(t_parse_manager *manager);
t_return_code	hex_color_state(t_parse_manager *manager);

t_return_code	colon_text_state(t_parse_manager *manager);
t_return_code	space_text_state(t_parse_manager *manager);
t_return_code	dquote_start_text_state(t_parse_manager *manager);
t_return_code	dquote_end_text_state(t_parse_manager *manager);
t_return_code	text_text_state(t_parse_manager *manager);

t_return_code	colon_pos_state(t_parse_manager *manager);
t_return_code	space_pos_state(t_parse_manager *manager);
t_return_code	pos_x_int_state(t_parse_manager *manager);
t_return_code	pos_x_period_state(t_parse_manager *manager);
t_return_code	pos_x_float_state(t_parse_manager *manager);
t_return_code	pos_comma_state(t_parse_manager *manager);
t_return_code	pos_space_state(t_parse_manager *manager);
t_return_code	pos_y_int_state(t_parse_manager *manager);
t_return_code	pos_y_period_state(t_parse_manager *manager);
t_return_code	pos_y_float_state(t_parse_manager *manager);

t_return_code	colon_dim_state(t_parse_manager *manager);
t_return_code	space_dim_state(t_parse_manager *manager);
t_return_code	dim_x_int_state(t_parse_manager *manager);
t_return_code	dim_x_period_state(t_parse_manager *manager);
t_return_code	dim_x_float_state(t_parse_manager *manager);
t_return_code	dim_comma_state(t_parse_manager *manager);
t_return_code	dim_space_state(t_parse_manager *manager);
t_return_code	dim_y_int_state(t_parse_manager *manager);
t_return_code	dim_y_period_state(t_parse_manager *manager);
t_return_code	dim_y_float_state(t_parse_manager *manager);

t_return_code	colon_onclick_state(t_parse_manager *manager);
t_return_code	space_onclick_state(t_parse_manager *manager);
t_return_code	str_onclick_state(t_parse_manager *manager);

t_return_code	colon_show_state(t_parse_manager *manager);
t_return_code	space_show_state(t_parse_manager *manager);
t_return_code	bool_show_state(t_parse_manager *manager);

t_return_code	colon_text_size_state(t_parse_manager *manager);
t_return_code	space_text_size_state(t_parse_manager *manager);
t_return_code	text_size_int_state(t_parse_manager *manager);
t_return_code	text_size_period_state(t_parse_manager *manager);
t_return_code	text_size_float_state(t_parse_manager *manager);

t_return_code	colon_clickable_state(t_parse_manager *manager);
t_return_code	space_clickable_state(t_parse_manager *manager);
t_return_code	bool_clickable_state(t_parse_manager *manager);

t_return_code	colon_layer_state(t_parse_manager *manager);
t_return_code	space_layer_state(t_parse_manager *manager);
t_return_code	min_layer_state(t_parse_manager *manager);
t_return_code	num_layer_state(t_parse_manager *manager);

t_return_code	colon_draw_method_state(t_parse_manager *manager);
t_return_code	space_draw_method_state(t_parse_manager *manager);
t_return_code	str_draw_method_state(t_parse_manager *manager);

t_return_code	colon_text_color_state(t_parse_manager *manager);
t_return_code	space_text_color_state(t_parse_manager *manager);
t_return_code	hash_text_color_state(t_parse_manager *manager);
t_return_code	hex_text_color_state(t_parse_manager *manager);

t_return_code	colon_text_font_state(t_parse_manager *manager);
t_return_code	space_text_font_state(t_parse_manager *manager);
t_return_code	str_text_font_state(t_parse_manager *manager);

t_return_code	colon_text_draw_method_state(t_parse_manager *manager);
t_return_code	space_text_draw_method_state(t_parse_manager *manager);
t_return_code	str_text_draw_method_state(t_parse_manager *manager);

t_return_code	colon_texture_state(t_parse_manager *manager);
t_return_code	space_texture_state(t_parse_manager *manager);
t_return_code	str_texture_state(t_parse_manager *manager);
t_return_code	period_texture_state(t_parse_manager *manager);
t_return_code	tga_texture_state(t_parse_manager *manager);

t_return_code	error_state(t_parse_manager *manager);
t_return_code	exit_state(t_parse_manager *manager);

#endif
