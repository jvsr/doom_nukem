/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   decals_on_vline.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 13:21:27 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:09:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"
#include "error.h"
#include "rinfo.h"

t_list		**decals_on_vline(t_wall *wall,
										float perc_hit, float len, t_list **out)
{
	t_list	*new;
	t_list	*temp;
	t_decal	*decal;

	temp = wall->decals;
	while (temp)
	{
		decal = temp->content;
		if (perc_hit >= decal->pos.x && perc_hit
		<= decal->pos.x + decal->size.x / len)
		{
			new = ft_lstnew(decal, sizeof(decal));
			if (new == NULL)
				error_msg_errno("Failed to alloc New Wall");
			ft_lstadd(out, new);
		}
		temp = temp->next;
	}
	return (out);
}
