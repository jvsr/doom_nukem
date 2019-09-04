/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformgetvisible.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 10:47:41 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 10:56:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_string.h"
#include "gui.h"
#include "libft/ft_bool.h"

t_bool		transformgetvisible(t_transform *transform)
{
	while (transform != NULL && !ft_strcmp(transform->name, GUI_NAME))
	{
		if (transform->visible == FALSE)
			return (FALSE);
		transform = transform->parent;
	}
	return (TRUE);
}
