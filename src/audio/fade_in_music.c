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
#include "audio.h"

void		fade_in_music(t_audio_man *man, t_music music, int time)
{
	Mix_FadeInMusic(man->track[music], -1, time);
}
