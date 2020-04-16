/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resume_sound.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:12:11 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

static int	resume(int index)
{
	Mix_Resume(index);
	return (0);
}

void		resume_sound(t_audio_man *man, char *const sound)
{
	effect_sound(man, sound, resume);
}
