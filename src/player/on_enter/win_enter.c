/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   win_enter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 10:04:20 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:41 by euan          ########   odam.nl         */
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
			if (((t_object*)(secs->objects + j)->content)->is_enemy)
				return ;
			j++;
		}
		i++;
	}
	map->has_won = TRUE;
}
