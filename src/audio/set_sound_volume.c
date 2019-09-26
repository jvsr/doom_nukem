/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_sound_volume.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:22:08 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 17:22:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

void	set_sound_volume(float volume)
{
	int i;

	i = 0;
	while (i < 16)
	{
		Mix_Volume(i, MIX_MAX_VOLUME * volume);
		i++;
	}
}
