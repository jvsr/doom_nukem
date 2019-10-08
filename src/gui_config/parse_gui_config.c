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
#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

int	entry_state(t_token**, t_parse_info**);
int	dash_state(t_token**, t_parse_info**);
int	space_state(t_token**, t_parse_info**);
int	id_state(t_token**, t_parse_info**);

int	colon_name_state(t_token**, t_parse_info**);
int	colon_color_state(t_token**, t_parse_info**);
int	colon_pos_state(t_token**, t_parse_info**);

int	space_name_state(t_token**, t_parse_info**);
int	space_color_state(t_token**, t_parse_info**);
int	space_pos_state(t_token**, t_parse_info**);

int	hash_color_state(t_token**, t_parse_info**);
int	hex_color_state(t_token**, t_parse_info**);
int	newline_attr_state(t_token**, t_parse_info**);
int	name_state(t_token**, t_parse_info**);
int	newline_name_state(t_token**, t_parse_info**);
int	indent_state(t_token**, t_parse_info**);
int	padding_state(t_token**, t_parse_info**);
int	error_state(t_token**, t_parse_info**);
int	exit_state(t_token**, t_parse_info**);

int (*state[])(t_token**, t_parse_info**) = {
	entry_state,		dash_state,			space_state,		id_state,
	colon_name_state,	colon_color_state,	colon_pos_state,
	space_name_state,	space_color_state,	space_pos_state,
	hash_color_state,	hex_color_state,	newline_attr_state,	name_state,
	newline_name_state,	indent_state,		padding_state,
	error_state,		exit_state,
																	};
enum state_code {
	entry,				dash,				space,				id,
	colon_name,			colon_color, 		colon_pos,
	space_name,			space_color,		space_pos,
	hash_color,			hex_color,			newline_attr,		name,
	newline_name,		indent,				padding,
	error,				end,
																	};
enum return_code {
	ok,			repeat,		fail,	special,	eot,	eot2,	eof,	type,
	pos,		dim,		color,	text,		text_draw_method,
	texture,	draw_method,		layer,		onclick,
											 						};

struct s_transition
{
	enum state_code src_state;
	enum return_code ret_code;
	enum state_code dst_state;
};

const struct s_transition transition_table[] = {
	{entry, ok, dash},
	{entry, fail, error},

	{dash, ok, space},
	{dash, fail, error},

	{space, ok, id},
	{space, fail, error},

	{id, type, colon_name},
	{id, color, colon_color},
	{id, pos, colon_pos},
	{id, fail, error},

	{colon_name, ok, space_name},
	{colon_name, fail, error},
	{colon_color, ok, space_color},
	{colon_color, fail, error},
	{colon_pos, ok, space_pos},
	{colon_pos, fail, error},

	{space_name, ok, name},
	{space_name, fail, error},
	{space_color, ok, hash_color},
	{space_color, fail, error},
	// {space_pos, ok, pos_x},
	{space_pos, fail, error},

	{hash_color, ok, hex_color},
	{hash_color, fail, error},

	{hex_color, ok, newline_attr},
	{hex_color, fail, error},

	{name, ok, newline_name},
	{name, fail, error},

	{newline_name, repeat, newline_name},
	{newline_name, ok, padding},
	{newline_name, eot, end},
	{newline_name, fail, error},

	{newline_attr, repeat, newline_attr},
	{newline_attr, ok, end},
	{newline_attr, eot, end},
	{newline_attr, fail, error},

	{indent, ok, dash},
	{indent, fail, error},
	{padding, ok, dash},
	{padding, fail, error},};

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

void	set_type(t_parse_info **parse_info, t_gui_type type)
{
	(*parse_info)->type = type;
}
void	set_name(t_parse_info **parse_info, const char *name)
{
	(*parse_info)->name = ft_strdup(name);
}
void	set_color(t_parse_info **parse_info, const char *color)
{
	(*parse_info)->color = ft_strdup(color);
}

int		set_rc_id(const char *id)
{
	enum return_code	rc;

	if (ft_strequ(id, "image"))
		rc = ok;
	else
		rc = fail;
	return (rc);
}

t_bool	check_type(const char *type)
{
	if (ft_strequ(type, "image")
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
	|| ft_strequ(type, "text_draw_method")
	|| ft_strequ(type, "texture")
	|| ft_strequ(type, "draw_method")
	|| ft_strequ(type, "layer")
	|| ft_strequ(type, "onclick"))
		return (TRUE);
	return (FALSE);
}

int		get_attr(const char *type)
{
	if (ft_strequ(type, "pos"))
		return (pos);
	else if (ft_strequ(type, "dim"))
		return (dim);
	else if (ft_strequ(type, "color"))
		return (color);
	else if (ft_strequ(type, "text"))
		return (text);
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
	return (fail);
}

void	create_child(t_parse_info **parse_info)
{
	t_parse_info *child;

	child = new_parse_info();
	child->parent = (*parse_info);
	if((*parse_info)->child)
		child->next = (*parse_info)->child;
	(*parse_info)->child = child;
}

int	entry_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	dash_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == SPACE)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	space_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == ID)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	id_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;
	static t_bool		first = TRUE;

	if ((*token)->next && (*token)->next->type == COLON)
	{
		if (check_type((*token)->token) || first == TRUE)
		{
			if (first == FALSE)
			{
				create_child(parse_info);
				(*parse_info) = (*parse_info)->child;
			}
			else
				first = FALSE;
			set_type(parse_info, get_gui_type_value((*token)->token));
			rc = type;
		}
		else if (check_attr((*token)->token))
		{
			rc = get_attr((*token)->token);
		}
		else
			rc = set_rc_id((*token)->token);
	}
	else
		rc = fail;
	return (rc);
}

int	colon_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == SPACE)
		rc = ok;
	else
		rc = fail;
	return (rc);
}
int	colon_name_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
int	colon_color_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}
int	colon_pos_state(t_token **token, t_parse_info **parse_info)
{
	return (colon_state(token, parse_info));
}

t_bool	is_newline(t_token_type type)
{
	if (type == LF || type == CRLF)
		return (TRUE);
	return (FALSE);
}

int	space_name_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->next
	&& ((*token)->next->type == ID || (*token)->next->type == PLAIN))
		rc = ok;
	else
		rc = fail;
	return (rc);
}
int	space_color_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == HASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}
int	space_pos_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == HASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	hash_color_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code rc;

	(void)parse_info;
	if ((*token)->next
	&& ((*token)->next->type == NUM || (*token)->next->type == PLAIN)
	&& ((*token)->next->token_amount == 6 || (*token)->next->token_amount == 8)
	&& ft_strishex((*token)->next->token))
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	hex_color_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code rc;

	set_color(parse_info, (*token)->token);
	if ((*token)->next
	&& is_newline((*token)->next->type))
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	name_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	set_name(parse_info, (*token)->token);
	if ((*token)->next
	&& is_newline((*token)->next->type))
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	newline_name_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code rc;

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

int	newline_attr_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code rc;

	(void)parse_info;
	if ((*token)->token_amount > 1)
		rc = repeat;
	else if ((*token)->next && (*token)->next->type == INDENT)
		rc = fail;
	else if ((*token)->next && (*token)->next->type == NODENT)
		rc = ok;
	else if ((*token)->next && (*token)->next->type == DEDENT)
	{
		(*parse_info) = (*parse_info)->parent;
		rc = ok;
	}
	else
		rc = fail;
	return (rc);
}

int	padding_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	indent_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code rc;

	(void)parse_info;
	if ((*token)->next && (*token)->next->type == DASH)
		rc = ok;
	else
		rc = fail;
	return (rc);
}

int	error_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	error_msg("Failed to parse", 20,
		ft_strformat("Unrecognized token \"%s\" in parser", (*token)->token));
	rc = fail;
	return (rc);
}

int	exit_state(t_token **token, t_parse_info **parse_info)
{
	enum return_code	rc;

	(void)parse_info;
	(void)token;
	rc = ok;
	return (rc);
}

int		lookup_state(enum state_code curstate, enum return_code rc) {
	size_t i;
	size_t max_items = sizeof(transition_table)/sizeof(transition_table[0]);

	i = 0;
	while(i < max_items) {
		if (transition_table[i].src_state == curstate
		&& transition_table[i].ret_code == rc)
			return (transition_table[i].dst_state);
		i++;
	}
	return(-1);
}

t_parse_info	*parse_gui_config(t_token *tokens, const char *state_name)
{
	enum return_code	rc;
	enum state_code		cur_state;
	t_parse_info		*parse_info;
	int					(* state_fun)(t_token**, t_parse_info**);

	cur_state = entry;
	parse_info = new_parse_info();
	while(1) {
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
