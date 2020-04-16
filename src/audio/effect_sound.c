/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   effect_sound.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:16:41 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:32:21 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "audio.h"

void	effect_sound(t_audio_man *man, char *const sound, int (*func)(int))
{
	Mix_Chunk	*cur;
	Mix_Chunk	*chunk;
	int			index;

	chunk = get_track_from_map(man->sound_map, sound);
	if (chunk == NULL)
	{
		ft_dprintf(2, "Trying to effect none existing sound '%s'\n", sound);
		return ;
	}
	index = 0;
	while (index < AUDIO_MAX_CHUNKS)
	{
		cur = Mix_GetChunk(index);
		if (cur != NULL && cur == chunk)
		{
			func(index);
			return ;
		}
		index++;
	}
}
