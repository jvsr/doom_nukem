/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_all_sound.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:41:30 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:00 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void		stop_all_sound(void)
{
	effect_all_sound(Mix_HaltChannel);
}
