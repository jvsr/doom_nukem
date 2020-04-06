/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_size_float_state.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:14:47 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

static void		set_text_size_float(t_parse_info *parse_info,
										const char *x_float)
{
	const int	x = ft_atoi(x_float);

	parse_info->text_size += (float)x / (ft_pow(10, ft_strlen(x_float)));
}

t_return_code	text_size_period_state(t_parse_manager *manager)
{
	return (check_next(manager->token, NUM));
}

t_return_code	text_size_float_state(t_parse_manager *manager)
{
	set_text_size_float(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
