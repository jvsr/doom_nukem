/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_button.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 16:58:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:56:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_mem.h"

#include "gui.h"
#include "error.h"

/*
** * Gui internal function
*/

t_button	*new_button(t_gui *ui)
{
	t_button *button;

	button = (t_button *)ft_memalloc(sizeof(t_button));
	if (button == NULL)
		error_msg(strerror(errno), errno, "Failed to alloc button");
	button->text = new_text(ui);
	button->image = new_image();
	return (button);
}
