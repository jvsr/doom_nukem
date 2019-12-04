/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_3d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:58:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/28 16:57:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "game.h"
#include "campaign.h"
#include "player.h"
#include "renderer.h"
#include "cmath.h"

unsigned short	get_starting_sector(t_coord pos, t_campaign *level)
{
	size_t			i;
	float			prev_close;
	float			close0;
	float			close1;
	t_campaign_wall	*wall;

	i = 0;
	prev_close = -1;
	while (i < level->wall_amount)
	{
		close0 = get_distance(&pos, level->wall[i]->vertex_begin);
		close1 = get_distance(&pos, level->wall[i]->vertex_begin);
		if (close0 < close1)
			close1 = close0;
		if (prev_close == -1 || close1 < prev_close)
		{
			prev_close = close1;
			wall = level->wall[i];
		}
		i++;
		printf("%i\n", level->wall[i]->sector_tag);
	}
	printf("%f\n", prev_close);
	return (wall->sector_tag);
}

void			render_3d(t_game *game, t_campaign *level, SDL_Surface *dst)
{
	static t_bool first = TRUE;

	if (first == TRUE)
	{
		ft_memcpy(&(game->player->pos),
			&level->player_start_pos, sizeof(t_coord));
		game->player->angle = (float)level->player_start_angle;
		game->player->cur_sector = get_starting_sector((t_coord)
			{game->player->pos.x, game->player->pos.y}, game->campaign);
		printf("%u\n", game->player->cur_sector);
		first = FALSE;
	}
	render_rooms(game, level, dst);
}
