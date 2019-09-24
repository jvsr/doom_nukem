/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_gui_child.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:54:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void		add_gui_child(t_gui *ui, t_transform *panel)
{
	panel->parent_type = GUI;
	panel->parent.ui = ui;
	add_to_children(&ui->children, panel);
	set_elem_redraw(panel);
}
