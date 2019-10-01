/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_sounds.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:04:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:04:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void	stop_sounds(t_audio_man *man, t_sounds sound)
{
	effect_sounds(man, sound, Mix_HaltChannel);
}
