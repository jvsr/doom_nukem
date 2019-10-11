/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id_state.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:54:45 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 14:54:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_bool.h"
#include "libft/ft_printf.h"

#include "lex.h"
#include "error.h"
#include "parse.h"

static t_bool	check_type(const char *type)
{
	if (ft_strequ(type, "image")
	|| ft_strequ(type, "text_block")
	|| ft_strequ(type, "panel")
	|| ft_strequ(type, "button"))
		return (TRUE);
	return (FALSE);
}

static void		create_child(t_parse_info **parse_info)
{
	t_parse_info *child;

	child = new_parse_info();
	child->parent = (*parse_info);
	if ((*parse_info)->child)
		child->next = (*parse_info)->child;
	(*parse_info)->child = child;
}

static void		set_type(t_parse_info **parse_info, t_gui_type type)
{
	(*parse_info)->type = type;
}

t_return_code	id_state(t_token **token, t_parse_info **parse_info)
{
	static t_bool	first = TRUE;

	if (check_next(token, COLON) != ok)
		return (fail);
	else if (check_type((*token)->token) || first == TRUE)
	{
		if (first == FALSE)
		{
			if ((*parse_info)->type != PANEL)
				error_msg("Parse error", 20,
					ft_strformat("%s gui_type is not allowed as a child of %s",
					(*token)->token, (*parse_info)->name));
			create_child(parse_info);
			(*parse_info) = (*parse_info)->child;
		}
		else
			first = FALSE;
		set_type(parse_info, get_gui_type_value((*token)->token));
		return (type);
	}
	else
		return (get_attr((*token)->token));
}
