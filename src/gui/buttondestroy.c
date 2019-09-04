/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttondestroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 13:46:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		buttondestroy(t_gui *ui, t_button *button,
												const t_bool destroychildren)
{
	if (button->transform.onclick != NULL)
		clickdestroy(ui, button->transform.name);
	ft_strdel(&button->text);
	if (destroychildren == TRUE)
		childrendestroy(ui, button->transform.children, TRUE);
	else if (button->transform.parent != NULL)
		ft_lstadd(&button->transform.parent->children,
			button->transform.children);
	SDL_FreeSurface(button->texture);
	ft_strdel(&button->transform.name);
	free(button);
	button = NULL;
}
