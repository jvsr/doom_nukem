/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_audio.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 11:16:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/01 11:16:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "libft/ft_mem.h"
#include "game.h"
#include "audio.h"
#include "error.h"

void	init_audio(t_game *game)
{
	int support;

	game->a_manager = (t_audio_manager*)ft_memalloc(sizeof(t_audio_manager));
	if (game->a_manager == NULL)
		error_msg(SDL_GetError(), 1, "Failed to allocate Audio Manager");
	if (Mix_OpenAudio(AUDIO_FREQ, AUDIO_S16SYS, AUDIO_CHANNELS, AUDIO_BUFFER)
		!= 0)
		error_msg(SDL_GetError(), 1, "Failed to init Audio Mixer");
	support = Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
	if (!(support & MIX_INIT_MP3))
		error_msg(SDL_GetError(), 1, "Failed to init Audio Mixer");
}
