/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fade_in_music.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:21:01 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:21:01 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "audio.h"

void		fade_in_music(t_audio_man *man, char *const music, int time)
{
	void	*chunk;

	chunk = get_track_from_map(man->music_map, music);
	if (chunk == NULL)
	{
		ft_dprintf(2, "Trying to fade none existing music '%s'\n", music);
		return ;
	}
	Mix_FadeInMusic(chunk, -1, time);
}
