/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:09:49 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:09:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"

#include "lex.h"
#include "parse.h"

static void		set_show(t_parse_info *parse_info, const char *show)
{
	const int	show_value = ft_atoi(show);

	parse_info->show = show_value;
}

t_return_code	colon_show_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_show_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}

t_return_code	bool_show_state(t_parse_manager *manager)
{
	set_show(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
