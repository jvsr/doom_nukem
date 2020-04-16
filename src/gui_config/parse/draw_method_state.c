/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_method_state.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:00:21 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static void		set_draw_method(t_parse_info *parse_info,
								const char *draw_method)
{
	const char	*name = parse_info->name;

	ft_strdel(&parse_info->draw_method);
	parse_info->draw_method = ft_strdup(draw_method);
	if (parse_info->draw_method == NULL)
		error_msg_errno(
			ft_strformat("Failed to alloc draw method in %s", name));
}

t_return_code	colon_draw_method_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_draw_method_state(t_parse_manager *manager)
{
	return (check_next_str(manager->token));
}

t_return_code	str_draw_method_state(t_parse_manager *manager)
{
	set_draw_method(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
