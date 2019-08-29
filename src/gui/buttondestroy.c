/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttondestroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:32:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		buttondestroy(t_button *button, const t_bool destroychildren)
{
	ft_strdel(&button->text);
	if (destroychildren == TRUE)
		childrendestroy(&button->transform.children, TRUE);
	else if (&button->transform.parent != NULL)
		ft_lstadd(&button->transform.parent->children,
			button->transform.children);
	SDL_FreeSurface(&button->texture);
	free(button);
	button = NULL;
}
