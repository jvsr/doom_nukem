/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_button.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:27:37 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:09:01 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_str.h"

#include "gui_internal.h"

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
