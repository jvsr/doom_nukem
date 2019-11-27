/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_sound.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:38:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:38:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void		play_sound(t_audio_man *man, t_sound sound)
{
	Mix_PlayChannel(-1, man->effect[sound], 0);
}
