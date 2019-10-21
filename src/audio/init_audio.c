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

#include <errno.h>
#include <SDL2/SDL_mixer.h>
#include "libft/ft_mem.h"
#include "game.h"
#include "setting.h"
#include "audio.h"
#include "error.h"

void	init_audio(t_game *game)
{
	int support;

	game->audio_man = (t_audio_man*)ft_memalloc(sizeof(t_audio_man));
	if (game->audio_man == NULL)
		error_msg_errno("Failed to allocate Audio Manager");
	if (Mix_OpenAudio(AUDIO_FREQ, AUDIO_S16SYS, AUDIO_CHANNELS, AUDIO_BUFFER)
		!= 0)
		error_msg_sdl(EIO, "Failed to open Audio Mixer");
	support = Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
	if (!(support & MIX_INIT_MP3))
		error_msg_sdl(EIO, "Failed to init Audio Mixer");
	set_sound_volume(game->setting->sound_volume);
	set_music_volume(game->setting->music_volume);
}
