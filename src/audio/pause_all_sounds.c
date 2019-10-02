/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pause_all_sounds.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:50:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:50:22 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

static int	pause(int index)
{
	Mix_Pause(index);
	return (0);
}

void		pause_all_sounds(void)
{
	effect_all_sounds(pause);
}
