/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_gview.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:37:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 17:37:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_mem.h"

#include "gui.h"
#include "error.h"

t_gview		*new_gview(void)
{
	t_gview *gview;

	gview = (t_gview *)ft_memalloc(sizeof(t_gview));
	if (gview == NULL)
		error_msg_errno("Failed to alloc panel");
	return (gview);
}
