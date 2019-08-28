/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttondestroy.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:41:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		buttondestroy(t_button *button)
{
	ft_strdel(&button->text);
	ft_lstdel(&button->transform.children, NULL);
	SDL_FreeSurface(&button->texture);
	free(button);
	button = NULL;
}
