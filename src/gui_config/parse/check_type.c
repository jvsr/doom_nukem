/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 14:56:08 by pholster       #+#    #+#                */
/*   Updated: 2019/10/14 14:56:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "parse.h"
#include "lex.h"
#include "gui.h"

t_return_code	check_type(const char *type_str)
{
	if (ft_strequ_nocase(type_str, "text"))
		return (fail);
	if (get_gui_type_value(type_str) != GUI_UNDEFINED)
		return (type);
	else
		return (fail);
}
