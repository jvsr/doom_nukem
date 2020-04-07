/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_color_state.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:09:54 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:27 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_text_color(t_parse_info *parse_info,
										const char *text_color)
{
	ft_strcpy(parse_info->text_color, text_color);
}

t_return_code	colon_text_color_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_text_color_state(t_parse_manager *manager)
{
	return (check_next(manager->token, HASH));
}

t_return_code	hash_text_color_state(t_parse_manager *manager)
{
	if (check_next_hex(manager->token) == ok
	&& (manager->token->next->token_amount == 6
	|| manager->token->next->token_amount == 8))
		return (ok);
	else
		return (fail);
}

t_return_code	hex_text_color_state(t_parse_manager *manager)
{
	set_text_color(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
