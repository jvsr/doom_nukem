/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_all_sounds.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:41:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:41:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "audio.h"

void		stop_all_sounds(void)
{
	effect_all_sounds(Mix_HaltChannel);
}
