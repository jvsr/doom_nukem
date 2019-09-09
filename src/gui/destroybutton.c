/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroybutton.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:20:47 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		destroybutton(t_gui *ui, t_button *button,
												const t_bool delchildren)
{
	if (button->transform.onclick != NULL)
		destroyclick(ui, button->transform.name);
	ft_strdel(&button->text);
	if (delchildren == TRUE)
		destroychildren(ui, button->transform.children, TRUE);
	else if (button->transform.parent != NULL)
		ft_lstadd(&button->transform.parent->children,
			button->transform.children);
	SDL_FreeSurface(button->texture);
	ft_strdel(&button->transform.name);
	free(button);
	button = NULL;
}
