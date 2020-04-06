/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   name_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:02:07 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static void		set_name(t_parse_info *parse_info, const char *name)
{
	parse_info->name = ft_strdup(name);
	if (parse_info->name == NULL)
		error_msg_errno(ft_strformat("Failed to alloc name in %s", name));
}

t_return_code	colon_name_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_name_state(t_parse_manager *manager)
{
	return (check_next_str(manager->token));
}

t_return_code	name_state(t_parse_manager *manager)
{
	set_name(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
