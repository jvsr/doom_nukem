/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fade_out_music.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:23:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:23:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void	fade_out_music(int time)
{
	Mix_FadeOutMusic(time);
}
