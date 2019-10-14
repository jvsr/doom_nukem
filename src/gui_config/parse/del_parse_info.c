/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_parse_info.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 15:41:15 by pholster       #+#    #+#                */
/*   Updated: 2019/09/30 15:41:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_mem.h"

#include "parse.h"

void	del_parse_info(t_parse_info **parse_info)
{
	if (*parse_info == NULL)
		return ;
	ft_strdel(&(*parse_info)->name);
	ft_strdel(&(*parse_info)->color);
	ft_strdel(&(*parse_info)->draw_method);
	ft_strdel(&(*parse_info)->text);
	ft_strdel(&(*parse_info)->text_color);
	ft_strdel(&(*parse_info)->text_draw_method);
	ft_strdel(&(*parse_info)->text_font);
	ft_strdel(&(*parse_info)->onclick);
	ft_memdel((void **)parse_info);
}
