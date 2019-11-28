/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_wall_to_out.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 11:32:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/25 11:32:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "game.h"
#include "cmath.h"
#include "map.h"
#include "player.h"
#include "renderer.h"
#include "setting.h"

static void		ensure_sides(t_coord *ang)
{
	float f_ang;

	if (ang->x < ang->y)
		return ;
	f_ang = ang->x;
	ang->x = ang->y;
	ang->y = f_ang;
}

static t_point	get_ang_range(t_coord *angs, float parts, float ang)
{
	int		i;
	int		k;

	i = 0;
	k = -1;
	while (i < RENDER_THREAD_COUNT)
	{
		if (k == -1)
		{
			if ((float)i * parts < (angs->x - ang))
				k = i;
		}
		else
		{
			if ((float)i * parts > (angs->y - ang))
				break ;
		}
		i++;
	}
	return ((t_point){k, i});
}

void			add_wall_to_out(t_list **out_walls,
									t_wall *wall, t_game *game, float parts)
{
	t_point	range;
	t_coord	angle_range;
	t_coord	tmp;

	angle_range.x = get_angle_from_vector(get_vector_from_points(
				&(t_coord){game->player->pos.x, game->player->pos.y},
				&wall->start, &tmp));
	angle_range.y = get_angle_from_vector(get_vector_from_points(
				&(t_coord){game->player->pos.x, game->player->pos.y},
				&wall->end, &tmp));
	ensure_sides(&angle_range);
	range = get_ang_range(&angle_range, parts,
				(float)game->player->angle - ((float)game->setting->fov / 2));
	while (range.x < range.y)
	{
		ft_lstaddbck(&out_walls[range.x], ft_lstnew(wall, sizeof(wall)));
		range.x++;
	}
}
