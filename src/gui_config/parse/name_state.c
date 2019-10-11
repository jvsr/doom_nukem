/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   name_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:02:07 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:02:07 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static void		set_name(t_parse_info **parse_info, const char *name)
{
	(*parse_info)->name = ft_strdup(name);
	if ((*parse_info)->name == NULL)
		error_msg_errno(ft_strformat("Failed to alloc name in %s", name));
}

t_return_code	colon_name_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_name_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_str(token));
}

t_return_code	name_state(t_token **token, t_parse_info **parse_info)
{
	set_name(parse_info, (*token)->token);
	return (check_next_newline(token));
}
