/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_elem_show.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 10:47:41 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:05 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "gui.h"

t_bool		get_elem_show(t_transform *elem)
{
	if (elem->show)
		return (FALSE);
	while (elem->parent_type == ELEM)
	{
		elem = elem->parent.elem;
		if (elem->show == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
