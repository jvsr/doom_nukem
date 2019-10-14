/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onclick_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:56:29 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 16:56:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static void		set_onclick(t_parse_info *parse_info, const char *onclick)
{
	const char	*name = parse_info->name;

	ft_strdel(&parse_info->onclick);
	parse_info->onclick = ft_strdup(onclick);
	if (parse_info->onclick == NULL)
		error_msg_errno(ft_strformat("Failed to alloc onclick in %s", name));
}

t_return_code	colon_onclick_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_onclick_state(t_parse_manager *manager)
{
	return (check_next_str(manager->token));
}

t_return_code	str_onclick_state(t_parse_manager *manager)
{
	set_onclick(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
