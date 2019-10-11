/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_size_int_state.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:14:47 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:14:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"

#include "lex.h"
#include "parse.h"

static void		set_text_size_int(t_parse_info **parse_info, const char *x_int)
{
	const int	x = ft_atoi(x_int);

	(*parse_info)->text_size = x;
}

t_return_code	colon_text_size_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_text_size_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}

t_return_code	text_size_int_state(t_token **token, t_parse_info **parse_info)
{
	set_text_size_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}
