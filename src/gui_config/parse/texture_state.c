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

t_return_code	colon_texture_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_texture_state(t_parse_manager *manager)
{
	return (check_next_str(manager->token));
}

t_return_code	str_texture_state(t_parse_manager *manager)
{
	ft_strcpy(manager->parse_info->texture, manager->token->token);
	return (check_next(manager->token, PERIOD));
}

t_return_code	period_texture_state(t_parse_manager *manager)
{
	if (check_next(manager->token, ID) == ok
	&& ft_strequ(manager->token->next->token, "tga"))
		return (ok);
	return (fail);
}

t_return_code	tga_texture_state(t_parse_manager *manager)
{
	return (check_next_newline(manager->token));
}
