/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_exec_gui_button.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 21:18:58 by pholster       #+#    #+#                */
/*   Updated: 2019/10/02 21:18:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	set_exec_gui_button(t_transform *elem, t_parse_info *elem_info)
{
	set_exec_gui_text(elem, elem_info);
	set_exec_gui_image(elem, elem_info);
}
