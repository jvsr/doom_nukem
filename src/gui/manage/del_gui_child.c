/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_gui_child.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:50:04 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:15 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

void	del_gui_child(t_gui *ui, const char *name)
{
	del_child(&ui->children, name);
}
