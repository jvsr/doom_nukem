/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   decals_on_vline.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:21:27 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/06 13:21:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"
#include "rinfo.h"

t_list		**decals_on_vline(t_wall *wall,
										float perc_hit, float len, t_list **out)
{
	t_list	*temp;
	t_decal	*decal;

	temp = wall->decals;
	while (temp)
	{
		decal = temp->content;
		if (perc_hit >= decal->pos.x &&
			perc_hit <= decal->pos.x + decal->size.x / len)
			ft_lstadd(out, ft_lstnew(decal, sizeof(decal)));
		temp = temp->next;
	}
	return (out);
}
