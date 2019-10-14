/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:05:36 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:05:36 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_color(t_parse_info *parse_info, const char *color)
{
	ft_strcpy(parse_info->color, color);
}

t_return_code	colon_color_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_color_state(t_parse_manager *manager)
{
	return (check_next(manager->token, HASH));
}

t_return_code	hash_color_state(t_parse_manager *manager)
{
	const t_token	*next = manager->token->next;

	if (check_next_hex(manager->token) == ok
	&& (next->token_amount == 6 || next->token_amount == 8))
		return (ok);
	else
		return (fail);
}

t_return_code	hex_color_state(t_parse_manager *manager)
{
	set_color(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
