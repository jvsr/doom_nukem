/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pos_y_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:20:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:20:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_pos_y_int(t_parse_info **parse_info, const char *y_int)
{
	const int	y = ft_atoi(y_int);

	(*parse_info)->pos.y = y;
}

static void		set_pos_y_float(t_parse_info **parse_info, const char *y_float)
{
	const int	y = ft_atoi(y_float);

	(*parse_info)->pos.y += (float)y / (ft_pow(10, ft_strlen(y_float)));
}

t_return_code	pos_y_int_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_y_int(parse_info, (*token)->token);
	return (check_next(token, PERIOD));
}

t_return_code	pos_y_period_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, NUM));
}

t_return_code	pos_y_float_state(t_token **token, t_parse_info **parse_info)
{
	set_pos_y_float(parse_info, (*token)->token);
	return (check_next_newline(token));
}
