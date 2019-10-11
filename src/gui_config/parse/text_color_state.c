/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_color_state.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:09:54 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:09:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_text_color(t_parse_info **parse_info,
										const char *text_color)
{
	ft_strcpy((*parse_info)->text_color, text_color);
}

t_return_code	colon_text_color_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_text_color_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, HASH));
}

t_return_code	hash_text_color_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	if (check_next_hex(token) == ok
	&& ((*token)->next->token_amount == 6 || (*token)->next->token_amount == 8))
		return (ok);
	else
		return (fail);
}

t_return_code	hex_text_color_state(t_token **token,
										t_parse_info **parse_info)
{
	set_text_color(parse_info, (*token)->token);
	return (check_next_newline(token));
}
