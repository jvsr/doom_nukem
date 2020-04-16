/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   layer_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:07:39 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:51 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"

#include "lex.h"
#include "parse.h"

static void		set_layer(t_parse_info *parse_info, const char *layer)
{
	const int	layer_value = ft_atoi(layer);

	if (parse_info->layer == -1)
		parse_info->layer = -layer_value;
	else
		parse_info->layer = layer_value;
}

t_return_code	colon_layer_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_layer_state(t_parse_manager *manager)
{
	if (check_next(manager->token, DASH))
		return (min);
	else
		return (check_next(manager->token, NUM));
}

t_return_code	min_layer_state(t_parse_manager *manager)
{
	set_layer(manager->parse_info, "-1");
	return (check_next(manager->token, NUM));
}

t_return_code	num_layer_state(t_parse_manager *manager)
{
	set_layer(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
