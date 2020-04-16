/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pause_all_sound.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:50:22 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:42 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

static int	pause(int index)
{
	Mix_Pause(index);
	return (0);
}

void		pause_all_sound(void)
{
	effect_all_sound(pause);
}
