/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_rooms.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:07:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/13 11:18:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "game.h"
#include "cmath.h"
#include "map.h"
#include "player.h"
#include "renderer.h"
#include "setting.h"

static t_wall	*get_wall(t_list **walls)
{
	t_list *first;
	t_wall *ret;

	first = *walls;
	*walls = first->next;
	ret = first->content;
	ft_lstdelone(&first, NULL);
	return (ret);
}

static void		split_walls(t_list **out_walls,
							t_game *game, t_list *walls, float parts)
{
	t_wall *wall;

	while (walls != NULL)
	{
		wall = get_wall(&walls);
		add_wall_to_out(out_walls, wall, game, parts);
	}
}

void			render_rooms(t_game *game, t_level *level)
{
	t_list	*walls;
	int		mask[game->surface->w * game->surface->h];
	t_list	*out_walls[RENDER_THREAD_COUNT];
	int		i;
	float	parts;

	ft_bzero(mask, game->surface->w * game->surface->h);
	walls = get_bunches(game, level);
	parts = game->setting->fov / RENDER_THREAD_COUNT;
	split_walls(out_walls, game, walls, parts);
	i = 0;
	while (i < RENDER_THREAD_COUNT)
	{
		render_part(game,
					(t_coord){i * parts, (i + 1) * parts}, out_walls[i], mask);
		i++;
	}
}
