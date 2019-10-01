/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pause_music.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:28:34 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:28:34 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

void		pause_music(void)
{
	Mix_PauseMusic();
}
