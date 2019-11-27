/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resume_all_sound.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:55:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:55:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

static int	resume(int index)
{
	Mix_Resume(index);
	return (0);
}

void		resume_all_sound(void)
{
	effect_all_sound(resume);
}
