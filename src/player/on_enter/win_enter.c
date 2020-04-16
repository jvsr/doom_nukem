/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   win_enter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 10:04:20 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 14:18:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "rinfo.h"
#include "game.h"

void		win_enter(t_game *game, t_sector *cur_sec)
{
	t_map		*map;
	t_sector	*secs;
	t_uint64	i;
	t_uint64	j;

	map = game->map;
	i = 0;
	(void)cur_sec;
	while (i < map->sector_count)
	{
		j = 0;
		secs = map->sectors + i;
		while (j < secs->object_count)
		{
			if (((t_object*)ft_lstindex(secs->objects, j)->content)->is_enemy &&
				((t_enemy*)((t_object*)
				ft_lstindex(secs->objects, j)->content)->data)->health > 0)
				return ;
			j++;
		}
		i++;
	}
	map->has_won = TRUE;
}
