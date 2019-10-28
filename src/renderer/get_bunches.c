/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_bunches.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 10:56:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/28 16:56:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map.h"
#include "player.h"
#include "game.h"
#include "types.h"
#include "renderer.h"

t_list	*add_walls(t_sector *sector, t_level *level, t_list *sectors)
{
	t_wall		**walls;
	t_uint32	i;
	float		normal;
	t_list		*lst;

	lst = NULL;
	walls = get_walls_from_sector(sector, level);
	i = 0;
	while (i < sector->wallcount)
	{
		normal = (walls[i]->start.x * walls[i]->end.y) -
			(walls[i]->end.x * walls[i]->start.y);
		if (normal > 0.7)
			continue;
		if (walls[i]->is_portal == TRUE)
			ft_lstaddbck(&sectors,ft_lstnew(
				level->sectors[walls[i]->sector_portal], sizeof(t_sector*)));
		ft_lstaddbck(&lst, ft_lstnew(walls[i], sizeof(sizeof(t_wall*))));
		i++;
	}
	return (lst);
}

t_list	*get_walls(t_list *sectors, t_level *level)
{
	t_list *walls;

	walls = NULL;
	while (sectors != NULL)
	{
		ft_lstaddbck(&walls, ft_lstnew(
			add_walls(sectors->content, level, sectors), sizeof(t_list*)));	
		sectors = sectors->next;
	}
	return (walls);
}

t_list	*get_bunches(t_game *game, t_level *level)
{
	t_list *sectors;
	t_list *walls;

	sectors = ft_lstnew(level->sectors[game->player->cur_sector],
		sizeof(t_sector*));
	walls = get_walls(sectors, level);
	ft_lstdel(&sectors, NULL);
	return (walls);
}
