/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroybutton.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 11:44:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		destroybutton(t_gui *ui, t_button **button,
												const t_bool delchildren)
{
	t_button *btn;

	btn = *button;
	if (btn->transform.onclick != NULL)
		destroyclick(ui, btn->transform.name);
	ft_strdel(&btn->text);
	if (delchildren == TRUE)
		destroychildren(ui, btn->transform.children, TRUE);
	else if (btn->transform.parent != NULL)
		ft_lstadd(&btn->transform.parent->children,
			btn->transform.children);
	SDL_FreeSurface(btn->texture);
	ft_strdel(&btn->transform.name);
	free(btn);
	button = NULL;
}
