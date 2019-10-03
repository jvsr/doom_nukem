/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resume_sounds.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:12:11 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:12:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

static int	resume(int index)
{
	Mix_Resume(index);
	return (0);
}

void		resume_sounds(t_audio_man *man, t_sounds sound)
{
	effect_sounds(man, sound, resume);
}
