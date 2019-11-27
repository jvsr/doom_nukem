/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_music.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 12:10:45 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 12:10:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "audio.h"

void		play_music(t_audio_man *man, char *const music)
{
	void	*chunk;

	chunk = get_track_from_map(man->music_map, music);
	if (chunk == NULL)
	{
		ft_dprintf(2, "Trying to play none existing music '%s'", music);
		return ;
	}
	Mix_HaltMusic();
	Mix_PlayMusic(chunk, -1);
}
