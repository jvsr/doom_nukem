/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resume_music.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:31:21 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 13:31:21 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

void	resume_music(void)
{
	Mix_ResumeMusic();
}
