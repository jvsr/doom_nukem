/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_sound.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:04:06 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:30:53 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void	stop_sound(t_audio_man *man, char *const sound)
{
	effect_sound(man, sound, Mix_HaltChannel);
}
