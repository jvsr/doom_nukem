/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_elem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 20:26:12 by pholster       #+#    #+#                */
/*   Updated: 2019/09/11 20:26:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "gui.h"
#include "error.h"

static void	new_gui_elem(t_gui *ui, t_gui_type type, t_gui_elem *gui_elem)
{
	if (type == TEXT)
		gui_elem->text = new_text(ui);
	else if (type == IMAGE)
		gui_elem->image = new_image();
	else if (type == BUTTON)
		gui_elem->button = new_button(ui);
	else if (type == PANEL)
		gui_elem->panel = new_panel();
}

t_transform	*new_elem(t_gui *ui, const char *name, t_gui_type type)
{
	t_transform	*new;

	new = (t_transform *)ft_memalloc(sizeof(t_transform));
	if (new == NULL)
		error_msg_errno("Failed to alloc transform surface");
	new->name = ft_strdup(name);
	if (new->name == NULL)
		error_msg_errno("Failed to alloc transform name");
	new->show = TRUE;
	new->redraw = TRUE;
	new->gui_type = type;
	new->has_alpha = (type == TEXT);
	new->clickable = (type != PANEL);
	new->parent_type = -1;
	new_gui_elem(ui, type, &new->gui_elem);
	return (new);
}
