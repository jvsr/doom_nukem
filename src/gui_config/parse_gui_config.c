/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_gui_config.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 12:35:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/01 15:53:32 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "lex.h"
#include "parse.h"

#include "error.h"

#include "libft/ft_str.h"
#include "libft/ft_num.h"
#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

typedef enum e_state_code	t_state_code;
typedef enum e_return_code	t_return_code;

t_return_code	entry_state(t_token**, t_parse_info**);
t_return_code	dash_state(t_token**, t_parse_info**);
t_return_code	space_state(t_token**, t_parse_info**);
t_return_code	id_state(t_token**, t_parse_info**);

t_return_code	colon_name_state(t_token**, t_parse_info**);
t_return_code	colon_color_state(t_token**, t_parse_info**);
t_return_code	colon_text_state(t_token**, t_parse_info**);
t_return_code	colon_pos_state(t_token**, t_parse_info**);
t_return_code	colon_dim_state(t_token**, t_parse_info**);
t_return_code	colon_onclick_state(t_token**, t_parse_info**);
t_return_code	colon_show_state(t_token**, t_parse_info**);
t_return_code	colon_clickable_state(t_token**, t_parse_info**);
t_return_code	colon_layer_state(t_token**, t_parse_info**);
t_return_code	colon_draw_method_state(t_token**, t_parse_info**);
t_return_code	colon_text_color_state(t_token**, t_parse_info**);
t_return_code	colon_texture_state(t_token**, t_parse_info**);

t_return_code	space_name_state(t_token**, t_parse_info**);
t_return_code	space_color_state(t_token**, t_parse_info**);
t_return_code	space_text_state(t_token**, t_parse_info**);
t_return_code	space_pos_state(t_token**, t_parse_info**);
t_return_code	space_dim_state(t_token**, t_parse_info**);
t_return_code	space_onclick_state(t_token**, t_parse_info**);
t_return_code	space_show_state(t_token**, t_parse_info**);
t_return_code	space_clickable_state(t_token**, t_parse_info**);
t_return_code	space_layer_state(t_token**, t_parse_info**);
t_return_code	space_draw_method_state(t_token**, t_parse_info**);
t_return_code	space_text_color_state(t_token**, t_parse_info**);
t_return_code	space_texture_state(t_token**, t_parse_info**);

t_return_code	dquote_start_text_state(t_token**, t_parse_info**);
t_return_code	dquote_end_text_state(t_token**, t_parse_info**);
t_return_code	text_text_state(t_token**, t_parse_info**);

t_return_code	pos_x_int_state(t_token**, t_parse_info**);
t_return_code	pos_x_period_state(t_token**, t_parse_info**);
t_return_code	pos_x_float_state(t_token**, t_parse_info**);
t_return_code	pos_comma_state(t_token**, t_parse_info**);
t_return_code	pos_space_state(t_token**, t_parse_info**);
t_return_code	pos_y_int_state(t_token**, t_parse_info**);
t_return_code	pos_y_period_state(t_token**, t_parse_info**);
t_return_code	pos_y_float_state(t_token**, t_parse_info**);

t_return_code	dim_x_int_state(t_token**, t_parse_info**);
t_return_code	dim_x_period_state(t_token**, t_parse_info**);
t_return_code	dim_x_float_state(t_token**, t_parse_info**);
t_return_code	dim_comma_state(t_token**, t_parse_info**);
t_return_code	dim_space_state(t_token**, t_parse_info**);
t_return_code	dim_y_int_state(t_token**, t_parse_info**);
t_return_code	dim_y_period_state(t_token**, t_parse_info**);
t_return_code	dim_y_float_state(t_token**, t_parse_info**);

t_return_code	str_texture_state(t_token**, t_parse_info**);
t_return_code	period_texture_state(t_token**, t_parse_info**);
t_return_code	id_texture_state(t_token **token, t_parse_info **parse_info);

t_return_code	hash_color_state(t_token**, t_parse_info**);
t_return_code	hex_color_state(t_token**, t_parse_info**);

t_return_code	hash_text_color_state(t_token**, t_parse_info**);
t_return_code	hex_text_color_state(t_token**, t_parse_info**);

t_return_code	newline_attr_state(t_token**, t_parse_info**);
t_return_code	name_state(t_token**, t_parse_info**);
t_return_code	newline_name_state(t_token**, t_parse_info**);
t_return_code	indent_state(t_token**, t_parse_info**);
t_return_code	padding_state(t_token**, t_parse_info**);
t_return_code	str_onclick_state(t_token**, t_parse_info**);
t_return_code	str_draw_method_state(t_token**, t_parse_info**);
t_return_code	bool_show_state(t_token**, t_parse_info**);
t_return_code	bool_clickable_state(t_token**, t_parse_info**);
t_return_code	num_layer_state(t_token**, t_parse_info**);
t_return_code	error_state(t_token**, t_parse_info**);
t_return_code	exit_state(t_token**, t_parse_info**);

t_return_code		(*state[])(t_token**, t_parse_info**) =
{
	entry_state,		dash_state,			space_state,		id_state,
	colon_name_state,	colon_color_state,	colon_text_state,	colon_pos_state,	colon_dim_state,	colon_onclick_state,
	space_name_state,	space_color_state,	space_text_state,	space_pos_state,	space_dim_state,	space_onclick_state,
	colon_show_state,	colon_clickable_state,					colon_layer_state,
	space_show_state,	space_clickable_state,					space_layer_state,
	colon_texture_state,colon_draw_method_state,				colon_text_color_state,
	space_texture_state,space_draw_method_state,				space_text_color_state,
	dquote_start_text_state,	dquote_end_text_state,			text_text_state,
	pos_x_int_state,	pos_x_period_state,	pos_x_float_state,
	pos_comma_state,	pos_space_state,
	pos_y_int_state,	pos_y_period_state,	pos_y_float_state,
	dim_x_int_state,	dim_x_period_state,	dim_x_float_state,
	dim_comma_state,	dim_space_state,
	dim_y_int_state,	dim_y_period_state,	dim_y_float_state,
	bool_show_state,	bool_clickable_state,					num_layer_state,
	hash_color_state,	hex_color_state,	newline_attr_state,	name_state,
	hash_text_color_state,					hex_text_color_state,
	newline_name_state,	indent_state,		padding_state,		str_onclick_state,
	str_texture_state,	period_texture_state, id_texture_state,	str_draw_method_state,
	error_state,		exit_state,
};
enum				e_state_code
{
	entry,				dash,				space,				id,
	colon_name,			colon_color, 		colon_text,			colon_pos,			colon_dim,			colon_onclick,
	space_name,			space_color,		space_text,			space_pos,			space_dim,			space_onclick,
	colon_show,			colon_clickable,	colon_layer,
	space_show,			space_clickable,	space_layer,
	colon_texture,		colon_draw_method,						colon_text_color,
	space_texture,		space_draw_method,						space_text_color,
	dquote_start_text,			dquote_end_text,				text_text,
	pos_x_int,			pos_x_period,		pos_x_float,
	pos_comma,			pos_space,
	pos_y_int,			pos_y_period,		pos_y_float,
	dim_x_int,			dim_x_period,		dim_x_float,
	dim_comma,			dim_space,
	dim_y_int,			dim_y_period,		dim_y_float,
	bool_show,			bool_clickable,							num_layer,
	hash_color,			hex_color,			newline_attr,		name,
	hash_text_color,						hex_text_color,
	newline_name,		indent,				padding,			str_onclick,
	str_texture,		period_texture,		id_texture,			str_draw_method,
	error,				end,
};
enum				e_return_code
{
	ok,			repeat,		fail,	special,	eot,	eoc,	eof,	type,
	pos,		dim,		color,	text,		text_draw_method,	text_color,
	text_size,	text_font,	texture,			draw_method,		layer,
	onclick,	show,		clickable,
};

typedef struct		s_transition
{
	t_state_code src_state;
	t_return_code ret_code;
	t_state_code dst_state;
}					t_transition;

const t_transition	g_transition_table[] =
{
	{entry, ok, dash},
	{entry, fail, error},

	{dash, ok, space},
	{dash, fail, error},

	{space, ok, id},
	{space, fail, error},

	{id, type, colon_name},
	{id, color, colon_color},
	{id, text, colon_text},
	{id, text_color, colon_text_color},
	{id, pos, colon_pos},
	{id, dim, colon_dim},
	{id, onclick, colon_onclick},
	{id, show, colon_show},
	{id, clickable, colon_clickable},
	{id, layer, colon_layer},
	{id, texture, colon_texture},
	{id, draw_method, colon_draw_method},
	{id, fail, error},

	{colon_name, ok, space_name},
	{colon_name, fail, error},
	{colon_color, ok, space_color},
	{colon_color, fail, error},
	{colon_text, ok, space_text},
	{colon_text, fail, error},
	{colon_text_color, ok, space_text_color},
	{colon_text_color, fail, error},
	{colon_pos, ok, space_pos},
	{colon_pos, fail, error},
	{colon_dim, ok, space_dim},
	{colon_dim, fail, error},
	{colon_onclick, ok, space_onclick},
	{colon_onclick, fail, error},
	{colon_show, ok, space_show},
	{colon_show, fail, error},
	{colon_clickable, ok, space_clickable},
	{colon_clickable, fail, error},
	{colon_layer, ok, space_layer},
	{colon_layer, fail, error},
	{colon_draw_method, ok, space_draw_method},
	{colon_draw_method, fail, error},
	{colon_texture, ok, space_texture},
	{colon_texture, fail, error},

	{space_name, ok, name},
	{space_name, fail, error},
	{space_color, ok, hash_color},
	{space_color, fail, error},
	{space_text, ok, dquote_start_text},
	{space_text, fail, error},
	{space_text_color, ok, hash_text_color},
	{space_text_color, fail, error},
	{space_pos, ok, pos_x_int},
	{space_pos, fail, error},
	{space_dim, ok, dim_x_int},
	{space_dim, fail, error},
	{space_onclick, ok, str_onclick},
	{space_onclick, fail, error},
	{space_show, ok, bool_show},
	{space_show, fail, error},
	{space_clickable, ok, bool_clickable},
	{space_clickable, fail, error},
	{space_layer, ok, num_layer},
	{space_layer, fail, error},
	{space_draw_method, ok, str_draw_method},
	{space_draw_method, fail, error},
	{space_texture, ok, str_texture},
	{space_texture, fail, error},

	{dquote_start_text, ok, dquote_end_text},
	{dquote_start_text, fail, text_text},
	{dquote_end_text, ok, newline_attr},
	{dquote_end_text, fail, error},
	{text_text, ok, dquote_end_text},
	{text_text, repeat, text_text},
	{text_text, fail, error},

	{bool_show, ok, newline_attr},
	{bool_show, fail, error},

	{bool_clickable, ok, newline_attr},
	{bool_clickable, fail, error},

	{num_layer, ok, newline_attr},
	{num_layer, fail, error},

	{str_texture, ok, period_texture},
	{str_texture, fail, error},
	{period_texture, ok, id_texture},
	{str_texture, fail, error},
	{id_texture, ok, newline_attr},
	{str_texture, fail, error},

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

	{hash_color, ok, hex_color},
	{hash_color, fail, error},
	{hex_color, ok, newline_attr},
	{hex_color, fail, error},

	{hash_text_color, ok, hex_text_color},
	{hash_text_color, fail, error},
	{hex_text_color, ok, newline_attr},
	{hex_text_color, fail, error},

	{str_draw_method, ok, newline_attr},
	{str_draw_method, fail, error},

	{str_onclick, ok, newline_attr},
	{str_onclick, fail, error},

	{name, ok, newline_name},
	{name, fail, error},

	{newline_name, repeat, newline_name},
	{newline_name, ok, padding},
	{newline_name, fail, error},

	{newline_attr, repeat, newline_attr},
	{newline_attr, ok, padding},
	{newline_attr, fail, error},

	{indent, ok, dash},
	{indent, fail, error},
	{padding, ok, dash},
	{padding, eoc, end},
	{padding, fail, error},
};

void	next_token(t_token **token)
{
	if ((*token)->token_amount == 1
	|| (*token)->type == ID
	|| (*token)->type == NUM
	|| (*token)->type == PLAIN)
		*token = (*token)->next;
	else
		(*token)->token_amount -= 1;
}

t_token_type	get_next_token_type(t_token **token)
{
	if ((*token)->token_amount == 1
	|| (*token)->type == ID
	|| (*token)->type == NUM
	|| (*token)->type == PLAIN)
	{
		if ((*token)->next)
			return ((*token)->next->type);
		else
			return (EOC);
	}
	else
		return ((*token)->type);
}

t_return_code	check_next(t_token **token, t_token_type type)
{
	if (get_next_token_type(token) == type)
		return (ok);
	return (fail);
}

t_return_code	check_next_hex(t_token **token)
{
	const t_token_type	type = get_next_token_type(token);

	if ((type == NUM || type == PLAIN) && ft_strishex((*token)->next->token))
		return (ok);
	return (fail);
}

t_return_code	check_next_str(t_token **token)
{
	const t_token_type	type = get_next_token_type(token);

	if (type == ID || type == PLAIN)
		return (ok);
	return (fail);
}

t_return_code	check_next_newline(t_token **token)
{
	const t_token_type	type = get_next_token_type(token);

	if (type == LF || type == CRLF)
		return (ok);
	return (fail);
}

void	set_type(t_parse_info **parse_info, t_gui_type type)
{
	(*parse_info)->type = type;
}
void	set_name(t_parse_info **parse_info, const char *name)
{
	(*parse_info)->name = ft_strdup(name);
	if ((*parse_info)->name == NULL)
		error_msg_errno(ft_strformat("Failed to alloc name in %s", name));
}
void	set_color(t_parse_info **parse_info, const char *color)
{
	ft_strcpy((*parse_info)->color, color);
}
void	set_text_color(t_parse_info **parse_info, const char *text_color)
{
	ft_strcpy((*parse_info)->text_color, text_color);
}
void	set_draw_method(t_parse_info **parse_info, const char *draw_method)
{
	const char	*name = (*parse_info)->name;

	ft_strdel(&(*parse_info)->draw_method);
	(*parse_info)->draw_method = ft_strdup(draw_method);
	if ((*parse_info)->draw_method == NULL)
		error_msg_errno(ft_strformat("Failed to alloc onclick in %s", name));
}
void	set_onclick(t_parse_info **parse_info, const char *onclick)
{
	const char	*name = (*parse_info)->name;

	ft_strdel(&(*parse_info)->onclick);
	(*parse_info)->onclick = ft_strdup(onclick);
	if ((*parse_info)->onclick == NULL)
		error_msg_errno(ft_strformat("Failed to alloc onclick in %s", name));
}
void	set_show(t_parse_info **parse_info, const char *show)
{
	const int	show_value = ft_atoi(show);

	(*parse_info)->show = show_value;
}
void	set_clickable(t_parse_info **parse_info, const char *clickable)
{
	const int	clickable_value = ft_atoi(clickable);

	(*parse_info)->clickable = clickable_value;
}
void	set_layer(t_parse_info **parse_info, const char *layer)
{
	const int	layer_value = ft_atoi(layer);

	(*parse_info)->layer = layer_value;
}
void	set_texture(t_parse_info **parse_info, const char *texture)
{
	ft_strcpy((*parse_info)->texture, texture);
}
void	set_pos_x_int(t_parse_info **parse_info, const char *x_int)
{
	const int	x = ft_atoi(x_int);

	(*parse_info)->pos.x = x;
}
void	set_pos_x_float(t_parse_info **parse_info, const char *x_float)
{
	const int	x = ft_atoi(x_float);

	(*parse_info)->pos.x += (float)x / (ft_pow(10, ft_strlen(x_float)));
}
void	set_pos_y_int(t_parse_info **parse_info, const char *y_int)
{
	const int	y = ft_atoi(y_int);

	(*parse_info)->pos.y = y;
}
void	set_pos_y_float(t_parse_info **parse_info, const char *y_float)
{
	const int	y = ft_atoi(y_float);

	(*parse_info)->pos.y += (float)y / (ft_pow(10, ft_strlen(y_float)));
}

void	set_dim_x_int(t_parse_info **parse_info, const char *x_int)
{
	const int	x = ft_atoi(x_int);

	(*parse_info)->dim.x = x;
}
void	set_dim_x_float(t_parse_info **parse_info, const char *x_float)
{
	const int	x = ft_atoi(x_float);

	(*parse_info)->dim.x += (float)x / (ft_pow(10, ft_strlen(x_float)));
}
void	set_dim_y_int(t_parse_info **parse_info, const char *y_int)
{
	const int	y = ft_atoi(y_int);

	(*parse_info)->dim.y = y;
}
void	set_dim_y_float(t_parse_info **parse_info, const char *y_float)
{
	const int	y = ft_atoi(y_float);

	(*parse_info)->dim.y += (float)y / (ft_pow(10, ft_strlen(y_float)));
}

t_return_code	set_rc_id(const char *id)
{
	if (ft_strequ(id, "image"))
		return (ok);
	else
		return (fail);
}

t_bool	check_type(const char *type)
{
	if (ft_strequ(type, "image")
	|| ft_strequ(type, "text_block")
	|| ft_strequ(type, "panel")
	|| ft_strequ(type, "button"))
		return (TRUE);
	return (FALSE);
}
t_bool	check_attr(const char *type)
{
	if (ft_strequ(type, "pos")
	|| ft_strequ(type, "dim")
	|| ft_strequ(type, "color")
	|| ft_strequ(type, "text")
	|| ft_strequ(type, "text_color")
	|| ft_strequ(type, "text_size")
	|| ft_strequ(type, "text_font")
	|| ft_strequ(type, "text_draw_method")
	|| ft_strequ(type, "texture")
	|| ft_strequ(type, "draw_method")
	|| ft_strequ(type, "layer")
	|| ft_strequ(type, "onclick")
	|| ft_strequ(type, "show")
	|| ft_strequ(type, "clickable"))
		return (TRUE);
	return (FALSE);
}

t_return_code	get_attr(const char *type)
{
	if (ft_strequ(type, "pos"))
		return (pos);
	else if (ft_strequ(type, "dim"))
		return (dim);
	else if (ft_strequ(type, "color"))
		return (color);
	else if (ft_strequ(type, "text"))
		return (text);
	else if (ft_strequ(type, "text_color"))
		return (text_color);
	else if (ft_strequ(type, "text_font"))
		return (text_font);
	else if (ft_strequ(type, "text_size"))
		return (text_size);
	else if (ft_strequ(type, "text_draw_method"))
		return (text_draw_method);
	else if (ft_strequ(type, "texture"))
		return (texture);
	else if (ft_strequ(type, "draw_method"))
		return (draw_method);
	else if (ft_strequ(type, "layer"))
		return (layer);
	else if (ft_strequ(type, "onclick"))
		return (onclick);
	else if (ft_strequ(type, "show"))
		return (show);
	else if (ft_strequ(type, "clickable"))
		return (clickable);
	return (fail);
}

void			create_child(t_parse_info **parse_info)
{
	t_parse_info *child;

	child = new_parse_info();
	child->parent = (*parse_info);
	if((*parse_info)->child)
		child->next = (*parse_info)->child;
	(*parse_info)->child = child;
}

t_return_code	entry_state(t_token **token, t_parse_info **parse_info)
{
	t_return_code	rc;

	(void)parse_info;
	if ((*token)->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

t_return_code	dash_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, ID));
}

t_return_code	id_state(t_token **token, t_parse_info **parse_info)
{
	static t_bool	first = TRUE;

	if (check_next(token, COLON) == ok)
	{
		if (check_type((*token)->token) || first == TRUE)
		{
			if (first == FALSE)
			{
				if ((*parse_info)->type != PANEL)
					error_msg("Parse error",
						20,
						ft_strformat("%s gui_type is not allowed as a child of %s", (*token)->token, (*parse_info)->name));
				create_child(parse_info);
				(*parse_info) = (*parse_info)->child;
			}
			else
				first = FALSE;
			set_type(parse_info, get_gui_type_value((*token)->token));
			return (type);
		}
		else if (check_attr((*token)->token))
			return (get_attr((*token)->token));
		else
			return (set_rc_id((*token)->token));
	}
	else
		return (fail);
}

t_return_code	colon_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	colon_name_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_color_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_text_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_text_color_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_pos_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_dim_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_draw_method_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_onclick_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_show_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_clickable_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_layer_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
t_return_code	colon_texture_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}

t_return_code	space_name_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}
t_return_code	space_color_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, HASH));
}
t_return_code	space_text_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, DQUOTE));
}
t_return_code	space_text_color_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, HASH));
}
t_return_code	space_pos_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	space_dim_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	space_draw_method_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}
t_return_code	space_onclick_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}
t_return_code	space_show_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	space_clickable_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	space_layer_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	space_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}

t_return_code	dquote_start_text_state(t_token **token, t_parse_info **parse_info)
{
	(*parse_info)->text = ft_strnew(0);
	return(check_next(token, DQUOTE));
}
t_return_code	dquote_end_text_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return(check_next_newline(token));
}
t_return_code	text_text_state(t_token **token, t_parse_info **parse_info)
{
	t_return_code	rc;

	ft_strappend(&(*parse_info)->text, (*token)->token);
	if (check_next(token, DQUOTE) == ok)
		rc = ok;
	else if (get_next_token_type(token) == EOC)
		rc = fail;
	else
		rc = repeat;
	return(rc);
}

t_return_code	hash_color_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	if (check_next_hex(token) == ok
	&& ((*token)->next->token_amount == 6 || (*token)->next->token_amount == 8))
		return (ok);
	else
		return (fail);
}

t_return_code	hash_text_color_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	if (check_next_hex(token) == ok
	&& ((*token)->next->token_amount == 6 || (*token)->next->token_amount == 8))
		return (ok);
	else
		return (fail);
}

t_return_code	hex_color_state(t_token **token, t_parse_info **parse_info)
{
	set_color(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	hex_text_color_state(t_token **token, t_parse_info **parse_info)
{
	set_text_color(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	pos_x_int_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_x_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}
t_return_code	pos_x_period_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	pos_x_float_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_x_float(parse_info, (*token)->token);
	return (check_next(token, COMMA));
}
t_return_code	pos_comma_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}
t_return_code	pos_space_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	pos_y_int_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_y_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}
t_return_code	pos_y_period_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	pos_y_float_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_y_float(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	dim_x_int_state(t_token **token, t_parse_info **parse_info)
{
	set_dim_x_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}
t_return_code	dim_x_period_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	dim_x_float_state(t_token **token, t_parse_info **parse_info)
{
	set_dim_x_float(parse_info, (*token)->token);
	return (check_next(token, COMMA));
}
t_return_code	dim_comma_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}
t_return_code	dim_space_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	dim_y_int_state(t_token **token, t_parse_info **parse_info)
{
	set_dim_y_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}
t_return_code	dim_y_period_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}
t_return_code	dim_y_float_state(t_token **token, t_parse_info **parse_info)
{
	set_dim_y_float(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	name_state(t_token **token, t_parse_info **parse_info)
{
	set_name(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	bool_show_state(t_token **token, t_parse_info **parse_info)
{
	set_show(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	num_layer_state(t_token **token, t_parse_info **parse_info)
{
	set_layer(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	str_texture_state(t_token **token, t_parse_info **parse_info)
{
	set_texture(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}

t_return_code	period_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	if (check_next(token, ID) == ok && ft_strequ((*token)->next->token, "tga"))
		return (ok);
	return (fail);
}

t_return_code	id_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_newline(token));
}

t_return_code	bool_clickable_state(t_token **token, t_parse_info **parse_info)
{
	set_clickable(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	str_draw_method_state(t_token **token, t_parse_info **parse_info)
{
	set_draw_method(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	str_onclick_state(t_token **token, t_parse_info **parse_info)
{
	set_onclick(parse_info, (*token)->token);
	return (check_next_newline(token));
}

t_return_code	newline_name_state(t_token **token, t_parse_info **parse_info)
{
	t_return_code rc;

	(void)parse_info;
	if ((*token)->token_amount > 1)
		rc = repeat;
	else if ((*token)->next && (*token)->next->type == INDENT)
		rc = ok;
	else if ((*token)->next && (*token)->next->type == NODENT)
	{
		(*parse_info) = (*parse_info)->parent;
		rc = ok;
	}
	else if ((*token)->next && (*token)->next->type == DEDENT)
	{
		(*parse_info) = (*parse_info)->parent;
		(*parse_info) = (*parse_info)->parent;
		rc = ok;
	}
	else
		rc = fail;
	return (rc);
}

t_return_code	newline_attr_state(t_token **token, t_parse_info **parse_info)
{
	t_return_code rc;
	const t_token_type	next_token_type = get_next_token_type(token);

	(void)parse_info;
	if ((*token)->token_amount > 1)
		rc = repeat;
	else if (next_token_type == INDENT)
		rc = fail;
	else if (next_token_type == NODENT)
		rc = ok;
	else if (next_token_type == DEDENT)
	{
		(*parse_info) = (*parse_info)->parent;
		if ((*token)->next->token_amount > 1)
			(*token)->next->token_amount--;
		while ((*token)->next->token_amount > 1)
		{
			(*parse_info) = (*parse_info)->parent;
			(*token)->next->token_amount--;
		}
		rc = ok;
	}
	else
		rc = fail;
	return (rc);
}

t_return_code	padding_state(t_token **token, t_parse_info **parse_info)
{
	const t_token_type	next_token_type = get_next_token_type(token);

	(void)parse_info;
	if (next_token_type == DASH)
		return (ok);
	if (next_token_type == EOC)
		return (eoc);
	return (fail);
}

t_return_code	indent_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, DASH));
}

t_return_code	error_state(t_token **token, t_parse_info **parse_info)
{
	const char		*message;

	(void)parse_info;
	if (*token)
		message = ft_strformat("Unrecognized token \"%s\" in parser", (*token)->token);
	else
		message = ft_strdup("Reached unexpected EOF");
	error_msg("Failed to parse", 20, message);
	return (fail);
}

t_return_code	exit_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	(void)token;
	return (ok);
}

t_state_code	lookup_state(t_state_code curstate, t_return_code rc) {
	size_t 			i;
	const size_t	max_items = sizeof(g_transition_table) / sizeof(t_transition);

	i = 0;
	while(i < max_items) {
		if (g_transition_table[i].src_state == curstate
		&& g_transition_table[i].ret_code == rc)
			return (g_transition_table[i].dst_state);
		i++;
	}
	error_msg("Unkown state", 1,
	ft_strformat("Undefined transition from %d with rc: '%d'", curstate, rc)); // use better error code
	return (-1);
}

t_parse_info	*parse_gui_config(t_token *tokens, const char *state_name)
{
	t_return_code	rc;
	t_state_code	cur_state;
	t_parse_info	*parse_info;
	t_return_code	(* state_fun)(t_token**, t_parse_info**);

	cur_state = entry;
	parse_info = new_parse_info();
	while(1)
	{
		if (tokens)
			ft_printf("%.2d - \'%s\', %d\n", cur_state, tokens->token, tokens->token_amount);
		state_fun = state[cur_state];
		rc = state_fun(&tokens, &parse_info);
		if (cur_state == end)
			break ;
		if (cur_state != entry)
			next_token(&tokens);
		cur_state = lookup_state(cur_state, rc);
	}

	return(parse_info);
	(void)state_name;
}
