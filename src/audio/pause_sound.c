/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pause_sound.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:04:06 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:34 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

static int	pause(int index)
{
	Mix_Pause(index);
	return (0);
}

void		pause_sound(t_audio_man *man, char *const sound)
{
	effect_sound(man, sound, pause);
}
