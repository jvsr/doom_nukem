/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_size_float_state.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:14:47 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:14:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_text_size_float(t_parse_info **parse_info,
										const char *x_float)
{
	const int	x = ft_atoi(x_float);

	(*parse_info)->text_size += (float)x / (ft_pow(10, ft_strlen(x_float)));
}

t_return_code	text_size_period_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}

t_return_code	text_size_float_state(t_token **token,
										t_parse_info **parse_info)
{
	set_text_size_float(parse_info, (*token)->token);
	return (check_next_newline(token));
}
