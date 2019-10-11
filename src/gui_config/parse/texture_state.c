/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_state.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:04:56 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:04:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

t_return_code	colon_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}

t_return_code	str_texture_state(t_token **token, t_parse_info **parse_info)
{
	ft_strcpy((*parse_info)->texture, (*token)->token);
	return (check_next(token, PERIOD));
}

t_return_code	period_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	if (check_next(token, ID) == ok && ft_strequ((*token)->next->token, "tga"))
		return (ok);
	return (fail);
}

t_return_code	tga_texture_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_newline(token));
}
