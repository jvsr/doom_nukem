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

static void		set_clickable(t_parse_info **parse_info, const char *clickable)
{
	const int	clickable_value = ft_atoi(clickable);

	(*parse_info)->clickable = clickable_value;
}

t_return_code	colon_clickable_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_clickable_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}

t_return_code	bool_clickable_state(t_token **token, t_parse_info **parse_info)
{
	set_clickable(parse_info, (*token)->token);
	return (check_next_newline(token));
}
