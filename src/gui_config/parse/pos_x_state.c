/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pos_x_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:19:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:19:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_pos_x_int(t_parse_info **parse_info, const char *x_int)
{
	const int	x = ft_atoi(x_int);

	(*parse_info)->pos.x = x;
}

static void		set_pos_x_float(t_parse_info **parse_info, const char *x_float)
{
	const int	x = ft_atoi(x_float);

	(*parse_info)->pos.x += (float)x / (ft_pow(10, ft_strlen(x_float)));
}

t_return_code	pos_x_int_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_x_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}

t_return_code	pos_x_period_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}

t_return_code	pos_x_float_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_x_float(parse_info, (*token)->token);
	return (check_next(token, COMMA));
}
