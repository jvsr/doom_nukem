/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_gui_child.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

void		add_gui_child(t_gui *ui, t_transform *panel)
{
	panel->parent_type = GUI;
	panel->parent.ui = ui;
	check_elem_duplicate(ui->children, panel);
	add_to_children(&ui->children, panel);
	set_elem_redraw(panel);
}
