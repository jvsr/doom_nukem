/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stop_music.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:35:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:35:25 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

void	stop_music(void)
{
	Mix_HaltMusic();
}
