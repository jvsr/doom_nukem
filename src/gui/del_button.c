/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_button.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/17 16:56:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_string.h"

#include "gui.h"

/*
** * Gui internal function
*/

void		del_button(t_button **button)
{
	if (button == NULL || *button == NULL)
		return ;
	del_text(&(*button)->text);
	del_image(&(*button)->image);
	free(*button);
	*button = NULL;
}
