/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id_state.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:54:45 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:52 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_bool.h"

#include "lex.h"
#include "error.h"
#include "parse.h"

static void		create_child(t_parse_info *parse_info)
{
	t_parse_info *child;

	child = new_parse_info();
	child->parent = parse_info;
	if (parse_info->child)
		child->next = parse_info->child;
	parse_info->child = child;
}

static void		id_error(t_parse_manager *manager)
{
	error_msg("Parse error", 20,
		ft_strformat("Line %zu: %s gui_type is not allowed as a child of %s",
		manager->line, manager->token->token, manager->parse_info->name));
}

static void		set_type(t_parse_info *parse_info, t_gui_type type)
{
	parse_info->type = type;
}

t_return_code	id_state(t_parse_manager *manager)
{
	t_token	*token;

	token = manager->token;
	if (check_next(token, COLON) != ok)
		return (fail);
	else if (check_type(token->token) == type)
	{
		if (manager->line != 1)
		{
			if (manager->parse_info->type != PANEL)
				id_error(manager);
			create_child(manager->parse_info);
			manager->parse_info = manager->parse_info->child;
		}
		set_type(manager->parse_info, get_gui_type_value(token->token));
		return (type);
	}
	else
		return (get_attr(token->token));
}
