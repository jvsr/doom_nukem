/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clickable_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:00:21 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:00:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"

#include "lex.h"
#include "parse.h"

static void		set_clickable(t_parse_info *parse_info, const char *clickable)
{
	const int	clickable_value = ft_atoi(clickable);

	parse_info->clickable = clickable_value;
}

t_return_code	colon_clickable_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_clickable_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}

t_return_code	bool_clickable_state(t_parse_manager *manager)
{
	set_clickable(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
