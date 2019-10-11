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

static void		set_color(t_parse_info **parse_info, const char *color)
{
	ft_strcpy((*parse_info)->color, color);
}

t_return_code	colon_color_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_color_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, HASH));
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

t_return_code	hex_color_state(t_token **token, t_parse_info **parse_info)
{
	set_color(parse_info, (*token)->token);
	return (check_next_newline(token));
}
