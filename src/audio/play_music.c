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
#include "audio.h"

void		play_music(t_audio_man *man, t_music music)
{
	Mix_HaltMusic();
	Mix_PlayMusic(man->track[music], -1);
}
