/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smash_glass.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 11:34:39 by euan          #+#    #+#                 */
/*   Updated: 2020/04/09 12:21:40 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "audio.h"
#include "rinfo.h"
#include "game.h"

static t_wall	*get_opposite(t_wall *glass, t_sector *sec)
{
	t_sector	*o_sec;
	t_uint64	i;

	i = 0;
	o_sec = glass->window;
	while (i < o_sec->wall_count)
	{
		if (o_sec->walls[i].window == sec)
			return (o_sec->walls + i);
		i++;
	}
	return (NULL);
}

void			smash_glass(t_game *game, t_wall *glass, t_sector *sec)
{
	t_wall	*o_glass;

	o_glass = get_opposite(glass, sec);
	if (o_glass != NULL)
		o_glass->is_window = FALSE;
	glass->is_window = FALSE;
	play_sound(game->audio_man, "window_shatter");
}
