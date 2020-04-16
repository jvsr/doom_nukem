/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transition_table.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:21:40 by pholster      #+#    #+#                 */
/*   Updated: 2019/10/11 14:21:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSITION_TABLE_H
# define TRANSITION_TABLE_H

# include "parse.h"

typedef	struct s_token	t_token;
typedef t_return_code	(t_state_fnc)(t_parse_manager *);

static t_state_fnc	*const g_state[] =
{
	entry_state,

	dash_state,
	space_state,
	id_state,

	newline_name_state,
	newline_attr_state,

	padding_state,

	colon_name_state,
	space_name_state,
	name_state,

	colon_color_state,
	space_color_state,
	hash_color_state,
	hex_color_state,

	colon_text_state,
	space_text_state,
	dquote_start_text_state,
	dquote_end_text_state,
	text_text_state,

	colon_pos_state,
	space_pos_state,
	pos_x_int_state,
	pos_x_period_state,
	pos_x_float_state,
	pos_comma_state,
	pos_space_state,
	pos_y_int_state,
	pos_y_period_state,
	pos_y_float_state,

	colon_dim_state,
	space_dim_state,
	dim_x_int_state,
	dim_x_period_state,
	dim_x_float_state,
	dim_comma_state,
	dim_space_state,
	dim_y_int_state,
	dim_y_period_state,
	dim_y_float_state,

	colon_onclick_state,
	space_onclick_state,
	str_onclick_state,

	colon_show_state,
	space_show_state,
	bool_show_state,

	colon_clickable_state,
	space_clickable_state,
	bool_clickable_state,

	colon_layer_state,
	space_layer_state,
	min_layer_state,
	num_layer_state,

	colon_text_font_state,
	space_text_font_state,
	str_text_font_state,

	colon_text_size_state,
	space_text_size_state,
	text_size_int_state,
	text_size_period_state,
	text_size_float_state,

	colon_texture_state,
	space_texture_state,
	str_texture_state,
	period_texture_state,
	tga_texture_state,

	colon_draw_method_state,
	space_draw_method_state,
	str_draw_method_state,

	colon_text_color_state,
	space_text_color_state,
	hash_text_color_state,
	hex_text_color_state,

	colon_text_draw_method_state,
	space_text_draw_method_state,
	str_text_draw_method_state,

	error_state,
	exit_state,
};

typedef enum				e_state_code
{
	entry,

	dash,
	space,
	id,

	newline_name,
	newline_attr,

	padding,

	colon_name,
	space_name,
	name,

	colon_color,
	space_color,
	hash_color,
	hex_color,

	colon_text,
	space_text,
	dquote_start_text,
	dquote_end_text,
	text_text,

	colon_pos,
	space_pos,
	pos_x_int,
	pos_x_period,
	pos_x_float,
	pos_comma,
	pos_space,
	pos_y_int,
	pos_y_period,
	pos_y_float,

	colon_dim,
	space_dim,
	dim_x_int,
	dim_x_period,
	dim_x_float,
	dim_comma,
	dim_space,
	dim_y_int,
	dim_y_period,
	dim_y_float,

	colon_onclick,
	space_onclick,
	str_onclick,

	colon_show,
	space_show,
	bool_show,

	colon_clickable,
	space_clickable,
	bool_clickable,

	colon_layer,
	space_layer,
	min_layer,
	num_layer,

	colon_text_font,
	space_text_font,
	str_text_font,

	colon_text_size,
	space_text_size,
	text_size_int,
	text_size_period,
	text_size_float,

	colon_texture,
	space_texture,
	str_texture,
	period_texture,
	tga_texture,

	colon_draw_method,
	space_draw_method,
	str_draw_method,

	colon_text_color,
	space_text_color,
	hash_text_color,
	hex_text_color,

	colon_text_draw_method,
	space_text_draw_method,
	str_text_draw_method,

	error,
	end,
}							t_state_code;

typedef struct				s_transition
{
	const t_state_code	src_state;
	const t_return_code	ret_code;
	const t_state_code	dst_state;
}							t_transition;

static t_transition const	g_transition_table[] =
{
	{entry, ok, dash},
	{entry, fail, error},

	{dash, ok, space},
	{dash, fail, error},
	{space, ok, id},
	{space, fail, error},

	{newline_name, repeat, newline_name},
	{newline_name, ok, padding},
	{newline_name, fail, error},
	{newline_attr, repeat, newline_attr},
	{newline_attr, ok, padding},
	{newline_attr, fail, error},

	{padding, ok, dash},
	{padding, eoc, end},
	{padding, fail, error},

	{id, type, colon_name},
	{colon_name, ok, space_name},
	{colon_name, fail, error},
	{space_name, ok, name},
	{space_name, fail, error},
	{name, ok, newline_name},
	{name, fail, error},

	{id, color, colon_color},
	{colon_color, ok, space_color},
	{colon_color, fail, error},
	{space_color, ok, hash_color},
	{space_color, fail, error},
	{hash_color, ok, hex_color},
	{hash_color, fail, error},
	{hex_color, ok, newline_attr},
	{hex_color, fail, error},

	{id, text, colon_text},
	{colon_text, ok, space_text},
	{colon_text, fail, error},
	{space_text, ok, dquote_start_text},
	{space_text, fail, error},
	{dquote_start_text, ok, dquote_end_text},
	{dquote_start_text, fail, text_text},
	{dquote_end_text, ok, newline_attr},
	{dquote_end_text, fail, error},
	{text_text, ok, dquote_end_text},
	{text_text, repeat, text_text},
	{text_text, fail, error},

	{id, text_color, colon_text_color},
	{colon_text_color, ok, space_text_color},
	{colon_text_color, fail, error},
	{space_text_color, ok, hash_text_color},
	{space_text_color, fail, error},
	{hash_text_color, ok, hex_text_color},
	{hash_text_color, fail, error},
	{hex_text_color, ok, newline_attr},
	{hex_text_color, fail, error},

	{id, pos, colon_pos},
	{colon_pos, ok, space_pos},
	{colon_pos, fail, error},
	{space_pos, ok, pos_x_int},
	{space_pos, fail, error},
	{pos_x_int, ok, pos_x_period},
	{pos_x_int, fail, error},
	{pos_x_period, ok, pos_x_float},
	{pos_x_period, fail, error},
	{pos_x_float, ok, pos_comma},
	{pos_x_float, fail, error},
	{pos_comma, ok, pos_space},
	{pos_comma, fail, error},
	{pos_space, ok, pos_y_int},
	{pos_space, fail, error},
	{pos_y_int, ok, pos_y_period},
	{pos_y_int, fail, error},
	{pos_y_period, ok, pos_y_float},
	{pos_y_period, fail, error},
	{pos_y_float, ok, newline_attr},
	{pos_y_float, fail, error},

	{id, dim, colon_dim},
	{colon_dim, ok, space_dim},
	{colon_dim, fail, error},
	{space_dim, ok, dim_x_int},
	{space_dim, fail, error},
	{dim_x_int, ok, dim_x_period},
	{dim_x_int, fail, error},
	{dim_x_period, ok, dim_x_float},
	{dim_x_period, fail, error},
	{dim_x_float, ok, dim_comma},
	{dim_x_float, fail, error},
	{dim_comma, ok, dim_space},
	{dim_comma, fail, error},
	{dim_space, ok, dim_y_int},
	{dim_space, fail, error},
	{dim_y_int, ok, dim_y_period},
	{dim_y_int, fail, error},
	{dim_y_period, ok, dim_y_float},
	{dim_y_period, fail, error},
	{dim_y_float, ok, newline_attr},
	{dim_y_float, fail, error},

	{id, onclick, colon_onclick},
	{colon_onclick, ok, space_onclick},
	{colon_onclick, fail, error},
	{space_onclick, ok, str_onclick},
	{space_onclick, fail, error},
	{str_onclick, ok, newline_attr},
	{str_onclick, fail, error},

	{id, show, colon_show},
	{colon_show, ok, space_show},
	{colon_show, fail, error},
	{space_show, ok, bool_show},
	{space_show, fail, error},
	{bool_show, ok, newline_attr},
	{bool_show, fail, error},

	{id, text_size, colon_text_size},
	{colon_text_size, ok, space_text_size},
	{colon_text_size, fail, error},
	{space_text_size, ok, text_size_int},
	{space_text_size, fail, error},
	{text_size_int, ok, text_size_period},
	{text_size_int, fail, error},
	{text_size_period, ok, text_size_float},
	{text_size_period, fail, error},
	{text_size_float, ok, newline_attr},
	{text_size_float, fail, error},

	{id, text_font, colon_text_font},
	{colon_text_font, ok, space_text_font},
	{colon_text_font, fail, error},
	{space_text_font, ok, str_text_font},
	{space_text_font, fail, error},
	{str_text_font, ok, newline_attr},
	{str_text_font, fail, error},

	{id, text_draw_method, colon_text_draw_method},
	{colon_text_draw_method, ok, space_text_draw_method},
	{colon_text_draw_method, fail, error},
	{space_text_draw_method, ok, str_text_draw_method},
	{space_text_draw_method, fail, error},
	{str_text_draw_method, ok, newline_attr},
	{str_text_draw_method, fail, error},

	{id, clickable, colon_clickable},
	{colon_clickable, ok, space_clickable},
	{colon_clickable, fail, error},
	{space_clickable, ok, bool_clickable},
	{space_clickable, fail, error},
	{bool_clickable, ok, newline_attr},
	{bool_clickable, fail, error},

	{id, layer, colon_layer},
	{colon_layer, ok, space_layer},
	{colon_layer, fail, error},
	{space_layer, ok, num_layer},
	{space_layer, min, min_layer},
	{space_layer, fail, error},
	{min_layer, ok, num_layer},
	{min_layer, fail, error},
	{num_layer, ok, newline_attr},
	{num_layer, fail, error},

	{id, texture, colon_texture},
	{colon_texture, ok, space_texture},
	{colon_texture, fail, error},
	{space_texture, ok, str_texture},
	{space_texture, fail, error},
	{str_texture, ok, period_texture},
	{str_texture, fail, error},
	{period_texture, ok, tga_texture},
	{period_texture, fail, error},
	{tga_texture, ok, newline_attr},
	{tga_texture, fail, error},

	{id, draw_method, colon_draw_method},
	{colon_draw_method, ok, space_draw_method},
	{colon_draw_method, fail, error},
	{space_draw_method, ok, str_draw_method},
	{space_draw_method, fail, error},
	{str_draw_method, ok, newline_attr},
	{str_draw_method, fail, error},

	{id, fail, error},
};

#endif
