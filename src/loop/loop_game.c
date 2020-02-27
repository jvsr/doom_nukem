/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:37:51 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/21 22:49:30 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_list.h"
#include "libft/ft_printf.h"

#include "gui.h"
#include "cmath.h"
#include "game.h"
#include "loop.h"
#include "player.h"

#include "rinfo.h"

void		check_enemy(t_player *player, t_object *object, t_map *map)
{
	float	dist;
	float	ang;
	t_coord	angl;
	t_coord	pos;

	if (object->is_enemy == TRUE)
	{
		dist = get_distance(&player->pos, &object->pos);
		if (dist < 100)
		{
			ang = get_angle_between_points(&object->pos, &player->pos);
			t_uint64 i = 0;
			while (i < map->sector_count) {
				t_uint64 j = 0;
				while (j < map->sectors[i].wall_count) {
					t_wall cur = map->sectors[i].walls[j];
					if (cur.is_portal == FALSE) {
						get_vector_from_angle(ang, &angl);
						if (get_collision(&object->pos, &angl, (t_coord[2]){cur.corner_0, cur.corner_1}, &pos))
						{
							t_coord newangl = {-(angl.x), -(angl.y)};
							if (get_collision(&player->pos, &newangl,
							(t_coord[2]){cur.corner_0, cur.corner_1}, &pos))
								return ;
						}
					}
					j++;
				}
				i++;
			}
		}
	}
}

void		enemy_move(t_game *game)
{
	size_t		i;
	size_t		j;
	const t_map	*map = game->map;

	i = 0;
	while (i < map->sector_count)
	{
		j = 0;
		while (j < map->sectors[i].object_count)
		{
			check_enemy(game->player, (ft_lstindex(map->sectors[i].objects, j))->content, game->map);
			j++;
		}
		i++;
	}
}

void		loop_game(t_game *game)
{
	player_move(game);
	enemy_move(game);
	loop_game_gui(game);
	if (game->player->is_dead)
		player_died(game);
}
