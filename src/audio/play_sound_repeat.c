/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_sound_repeat.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:00:39 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:00:39 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "audio.h"

void	play_sound_repeat(t_audio_man *man, char *const sound, int times)
{
	void	*chunk;

	chunk = get_track_from_map(man->sound_map, sound);
	if (chunk == NULL)
	{
		ft_dprintf(2, "Trying to effect none existing sound '%s'", sound);
		return ;
	}
	Mix_PlayChannel(-1, chunk, times);
}
