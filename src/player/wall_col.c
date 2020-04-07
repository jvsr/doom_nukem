/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_col.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:30:34 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:11 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "libft/ft_mem.h"
#include "game.h"
#include "error.h"
#include "setting.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"
#include "keymap.h"

#include <stdio.h>
#include <limits.h>

static t_bool	coll(t_coord c0, t_coord c1, t_coord c2, t_coord c3)
{
	t_coord b;
	t_coord d;
	t_coord c;
	t_coord dots;

	b = (t_coord){c1.x - c0.x, c1.y - c0.y};
	d = (t_coord){c3.x - c2.x, c3.y - c2.y};
	dots.x = b.x * d.y - b.y * d.x;
	if (dots.x == 0)
		return (FALSE);
	c = (t_coord){c2.x - c0.x, c2.y - c0.y};
	dots.y = (c.x * d.y - c.y * d.x) / dots.x;
	if (dots.y < 0 || dots.y > 1)
		return (FALSE);
	dots.y = (c.x * b.y - c.y * b.x) / dots.x;
	if (dots.y < 0 || dots.y > 1)
		return (FALSE);
	return (TRUE);
}

t_bool			wall_col(t_coord c0, t_coord c1, t_wall *wall)
{
	if (coll(c0, c1, wall->corner_0, wall->corner_1))
		return (TRUE);
	return (FALSE);
}

void			check_wall_col(t_tricoord coord, t_player *player,
						t_wall *wall, t_uint8 *col)
{
	if (wall_col(coord.x, player->pos, wall) == TRUE)
		*col |= 1;
	if (wall_col(coord.y, player->pos, wall) == TRUE)
		*col |= 2;
	if (wall_col(coord.xy, player->pos, wall) == TRUE)
		*col |= 4;
}

static void		add_wall(t_wall *wall, t_list **portals)
{
	t_list		*new_wall;

	new_wall = ft_lstnew(wall, sizeof(t_wall*));
	if (new_wall == NULL)
		error_msg_errno("Failed to alloc New Wall");
	ft_lstadd(portals, new_wall);
}

t_list			*check_walls(t_game *game, t_uint8 *col, t_tricoord coord,
														t_uint32 prev_sector)
{
	int			i;
	const int	max = game->map->sectors[game->player->cur_sector].wall_count;
	t_wall		*walls;
	t_list		*portals;

	portals = NULL;
	walls = game->map->sectors[game->player->cur_sector].walls;
	i = 0;
	while (i < max)
	{
		if (walls[i].is_portal == FALSE || walls[i].is_window == TRUE)
			check_wall_col(coord, game->player, &walls[i], col);
		else if (walls[i].is_portal == TRUE
		&& get_sector_id(game->map, walls[i].window) != prev_sector)
		{
			if (wall_col(coord.xy, game->player->pos, &walls[i]) == TRUE
			|| wall_col(coord.x, game->player->pos, &walls[i]) == TRUE
			|| wall_col(coord.y, game->player->pos, &walls[i]) == TRUE)
				add_wall(&walls[i], &portals);
		}
		if (*col == 7)
			return (portals);
		i++;
	}
	return (portals);
}
