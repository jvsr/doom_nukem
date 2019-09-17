/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_text.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:44:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 10:57:14 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_string.h"

#include "gui.h"

/*
** * Gui internal function
*/

void		del_text(t_text **text)
{
	if (text == NULL || *text == NULL)
		return ;
	ft_strdel(&(*text)->str);
	free(*text);
	*text = NULL;
}
