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

static void		set_show(t_parse_info **parse_info, const char *show)
{
	const int	show_value = ft_atoi(show);

	(*parse_info)->show = show_value;
}

t_return_code	colon_show_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_show_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}

t_return_code	bool_show_state(t_token **token, t_parse_info **parse_info)
{
	set_show(parse_info, (*token)->token);
	return (check_next_newline(token));
}
