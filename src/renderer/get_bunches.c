/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_bunches.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 10:56:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/28 15:00:44 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "campaign.h"
#include "player.h"
#include "game.h"
#include "types.h"
#include "renderer.h"

static int		is_between(float mag, t_mag *pmag)
{
	return (!(mag > pmag->start || mag < pmag->end));
}

static t_bool	handle_portal(t_campaign_wall *wall, t_campaign_sector *sector,
					t_list *secs, t_campaign *level)
{
	t_list			*tmp_lst;
	unsigned short	tmp;

	if (wall->sidedef_left == NULL || wall->sidedef_right == NULL)
		return (FALSE);
	if (wall->sidedef_left->sector == wall->sidedef_right->sector)
		return (FALSE);
	if (sector->sector_id == (size_t)wall->sidedef_left->sector)
		tmp = wall->sidedef_right->sector;
	else
		tmp = wall->sidedef_left->sector;
	tmp_lst = secs;
	while (tmp_lst)
	{
		if ((size_t)tmp == ((t_campaign_sector*)tmp_lst->content)->sector_id)
			return (FALSE);
		tmp_lst = tmp_lst->next;
	}
	ft_lstaddbck(&secs, ft_lstnew(get_sector(tmp, level->sector),
		sizeof(t_campaign_sector*)));
	return (TRUE);
}

static t_list	*add_walls(t_campaign_sector *sector,
					t_campaign *level, t_list *sectors, t_mag *mag)
{
	t_campaign_wall	**walls;
	t_uint32		i;
	float			normal;
	t_list			*lst;

	lst = NULL;
	walls = sector->wall;
	i = 0;
	while (i < sector->wall_amount)
	{
		normal = (walls[i]->vertex_begin->x * walls[i]->vertex_end->y) -
			(walls[i]->vertex_end->x * walls[i]->vertex_begin->y);
		if (is_between(normal, mag))
		{
			if (handle_portal(walls[i], sector, sectors, level))
				ft_lstaddbck(&lst, add_walls(ft_lstlast(lst)->content, level, sectors, mag));
			ft_lstaddbck(&lst, ft_lstnew(walls[i], sizeof(sizeof(t_campaign_wall*))));
		}
		i++;
	}
	return (lst);
}

static t_list	*get_walls(t_list *sectors, t_campaign *level, t_mag *mag)
{
	t_list *walls;

	walls = NULL;
	while (sectors != NULL)
	{
		ft_lstaddbck(&walls, ft_lstnew(
			add_walls(sectors->content, level, sectors, mag), sizeof(t_list*)));
		sectors = sectors->next;
	}
	return (walls);
}

t_list	*get_bunches(t_game *game, t_campaign *level)
{
	t_list *sectors;
	t_list *walls;

	sectors = ft_lstnew(get_sector(game->player->cur_sector, level->sector),
		sizeof(t_campaign_sector*));
	walls = get_walls(sectors, level, &game->player->mag);
	ft_lstdel(&sectors, NULL);
	return (walls);
}
