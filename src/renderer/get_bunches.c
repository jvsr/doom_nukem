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
#include "cmath.h"
#include "types.h"
#include "renderer.h"

static int		is_between(float mag, t_mag *pmag)
{
	if (pmag->start < pmag->end)
		return (mag >= pmag->start && mag <= pmag->end);
	return (mag <= pmag->start || mag >= pmag->end);
}

static void		handle_portal(t_campaign_wall *wall, t_campaign_sector *sector,
					t_list *secs, t_campaign *level)
{
	t_list				*tmp_lst;
	unsigned short		tmp;
	t_campaign_sector	*new;

	if (wall->sidedef_left == NULL || wall->sidedef_right == NULL)
		return ;
	if (wall->sidedef_left->sector == wall->sidedef_right->sector)
		return ;
	if (sector->sector_id == (size_t)wall->sidedef_left->sector)
		tmp = wall->sidedef_right->sector;
	else
		tmp = wall->sidedef_left->sector;	
	tmp_lst = secs;
	while (tmp_lst)
	{
		if ((size_t)tmp == ((t_campaign_sector*)tmp_lst->content)->sector_id)
			return ;
		tmp_lst = tmp_lst->next;
	}
	new = get_sector(tmp, level->sector);
	if (new != NULL)
		ft_lstaddbck(&secs, ft_lstnew(new, sizeof(t_campaign_sector*)));
	return ;
}

static t_list	*add_walls(t_campaign_sector *sector,
					t_campaign *level, t_list *sectors, t_mag *mag)
{
	t_campaign_wall	**walls;
	t_uint32		i;
	t_list			*lst;
	t_coord			output;

	lst = NULL;
	walls = sector->wall;
	i = 0;
	while (i < sector->wall_amount)
	{
		output = get_perps(get_angle_from_vector(get_vector_from_points(
				walls[i]->vertex_begin, walls[i]->vertex_end, &output)));
		if (is_between(output.x, mag) || is_between(output.y, mag))
		{
			handle_portal(walls[i], sector, sectors, level);
			ft_lstaddbck(&lst, ft_lstnew(walls[i], sizeof(t_campaign_wall*)));
		}
		i++;
	}
	return (lst);
}

static t_list	*get_walls(t_list *sectors, t_campaign *level, t_mag *mag)
{
	t_list *walls;
	t_list *tmp;
	t_list *new;

	walls = NULL;
	tmp = sectors;
	while (tmp != NULL)
	{
		new = add_walls(sectors->content, level, sectors, mag);
		if (new->content != NULL)
			ft_lstaddbck(&walls, new);
		else
			ft_lstdel(&new, NULL);
		tmp = tmp->next;
	}
	return (walls);
}

t_list	*get_bunches(t_game *game, t_campaign *level)
{
	t_list				*sectors;
	t_list				*walls;
	t_campaign_sector	*new;

	new = get_sector(game->player->cur_sector, level->sector);
	if (new == NULL)
		return (NULL);
	sectors = ft_lstnew(new ,sizeof(t_campaign_sector*));
	walls = get_walls(sectors, level, &game->player->mag);
	ft_lstdel(&sectors, NULL);
	return (walls);
}
