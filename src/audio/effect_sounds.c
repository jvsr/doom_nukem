/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   effect_sounds.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:16:41 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:16:41 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void	effect_sounds(t_audio_man *man, t_sound sound, int (*func)(int))
{
	Mix_Chunk	*chunk;
	int			index;

	chunk = man->effect[sound];
	index = 0;
	while (index < AUDIO_MAX_CHUNKS)
	{
		if (Mix_GetChunk(index) != NULL && Mix_GetChunk(index) == chunk)
			func(index);
		index++;
	}
}
