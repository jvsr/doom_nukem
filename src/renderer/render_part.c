/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_part.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:38:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/12 14:38:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "game.h"
#include "player.h"

static void		render_coloumn(t_game *game, int w, t_list *walls)
{
	
}

void		   	render_part(t_game *game, t_coord range, t_list *walls)
{
	float	indices[2];
	int		i;

	indices[1] = game->surface->w; //FOV / game->
	indices[0] = range.x;
	i = indices[1]; //FOV / indices[1]
	while (indices[0] < range.y)
	{
		render_coloumn(game, i, walls);
		indices[0] += indices[1];
		i++;
	}
}
