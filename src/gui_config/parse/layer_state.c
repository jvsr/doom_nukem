/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   layer_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:07:39 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:07:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"

#include "lex.h"
#include "parse.h"

static void		set_layer(t_parse_info **parse_info, const char *layer)
{
	const int	layer_value = ft_atoi(layer);

	if ((*parse_info)->layer == -1)
		(*parse_info)->layer = -layer_value;
	else
		(*parse_info)->layer = layer_value;
}

t_return_code	colon_layer_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_layer_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	if (check_next(token, DASH))
		return (min);
	else
		return (check_next(token, NUM));
}

t_return_code	min_layer_state(t_token **token, t_parse_info **parse_info)
{
	set_layer(parse_info, "-1");
	return (check_next(token, NUM));
}

t_return_code	num_layer_state(t_token **token, t_parse_info **parse_info)
{
	set_layer(parse_info, (*token)->token);
	return (check_next_newline(token));
}
