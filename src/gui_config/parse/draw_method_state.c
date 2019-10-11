/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_method_state.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:00:21 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 17:00:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static void		set_draw_method(t_parse_info **parse_info,
								const char *draw_method)
{
	const char	*name = (*parse_info)->name;

	ft_strdel(&(*parse_info)->draw_method);
	(*parse_info)->draw_method = ft_strdup(draw_method);
	if ((*parse_info)->draw_method == NULL)
		error_msg_errno(
			ft_strformat("Failed to alloc draw method in %s", name));
}

t_return_code	colon_draw_method_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_draw_method_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}

t_return_code	str_draw_method_state(t_token **token,
										t_parse_info **parse_info)
{
	set_draw_method(parse_info, (*token)->token);
	return (check_next_newline(token));
}
