/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_gui_child.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:50:04 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 11:50:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	del_gui_child(t_gui *ui, const char *name)
{
	del_child(&ui->children, name);
}
