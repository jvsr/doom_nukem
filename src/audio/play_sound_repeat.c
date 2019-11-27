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
#include "audio.h"

void	play_sound_repeat(t_audio_man *man, t_sound sound, int times)
{
	Mix_PlayChannel(-1, man->effect[sound], times);
}
