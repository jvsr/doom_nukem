/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:59:52 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/16 12:02:05 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "rinfo.h"
#include "cmath.h"
#include "player.h"

t_bool		check_far(const float dist, t_object *obj, t_game *game)
{
	const t_enemy	*enemy = obj->data;

	if (dist > 100)
	{
		if (enemy->no_los)
			enemy->no_los(game, obj);
		return (FALSE);
	}
	return (TRUE);
}

t_bool		check_wall(float ang, t_wall cur, t_object *obj, t_game *game)
{
	t_coord		angl;
	t_coord		pos;
	t_coord		newangl;

	get_vector_from_angle(ang, &angl);
	if (get_collision(&obj->pos, &angl,
	(t_coord[2]){cur.corner_0, cur.corner_1}, &pos))
	{
		newangl = (t_coord){-(angl.x), -(angl.y)};
		if (get_collision(&game->player->pos, &newangl,
		(t_coord[2]){cur.corner_0, cur.corner_1}, &pos))
			return (FALSE);
	}
	return (TRUE);
}

t_bool		check_collision(t_game *game, t_object *obj)
{
	float		ang;
	t_uint64	i;
	t_uint64	j;
	t_wall		cur;

	ang = get_angle_between_points(&obj->pos, &game->player->pos);
	i = 0;
	while (i < game->map->sector_count)
	{
		j = 0;
		while (j < game->map->sectors[i].wall_count)
		{
			cur = game->map->sectors[i].walls[j];
			if ((cur.is_portal == FALSE || cur.is_window == TRUE)
			&& check_wall(ang, cur, obj, game) == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool		check_enemy(t_game *game, t_object *obj)
{
	const t_enemy	*enemy = obj->data;
	const float		dist = get_distance(&game->player->pos, &obj->pos);

	if (obj != NULL && obj->is_enemy == TRUE && enemy->state != ENEMY_DEAD)
	{
		if (check_far(dist, obj, game) == FALSE)
			return (FALSE);
		if (dist > 5)
		{
			if (check_collision(game, obj) == TRUE)
			{
				if (enemy->on_los)
					enemy->on_los(game, obj, game->player);
				return (TRUE);
			}
			else if (enemy->no_los)
				enemy->no_los(game, obj);
		}
		else if (enemy->on_los)
			enemy->on_los(game, obj, game->player);
	}
	return (FALSE);
}
