/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_text.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:44:58 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:09:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_str.h"

#include "gui.h"

/*
** * Gui internal function
*/

void		del_text(t_text **text)
{
	if (text == NULL || *text == NULL)
		return ;
	ft_strdel(&(*text)->text);
	free(*text);
	*text = NULL;
}
