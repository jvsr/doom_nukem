/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_music_volume.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:18:03 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:09 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

void	set_music_volume(float volume)
{
	Mix_VolumeMusic(volume * MIX_MAX_VOLUME);
}
