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
#include "libft/ft_hash.h"

#include "game.h"
#include "init.h"
#include "setting.h"
#include "audio.h"
#include "error.h"

static void	alloc_hashmaps(t_audio_man *man)
{
	man->sound_map = ft_hashmapnew(SOUND_MAP_SIZE, &INIT_KEYMAP_ALGO);
	if (man->sound_map == NULL)
		error_msg_errno("Failed to allocate hashmap for sound");
	man->music_map = ft_hashmapnew(MUSIC_MAP_SIZE, &INIT_KEYMAP_ALGO);
	if (man->music_map == NULL)
		error_msg_errno("Failed to allocate hashmap for music");
}

void		init_audio(t_game *game)
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
	alloc_hashmaps(game->audio_man);
	set_sound_volume(game->setting->sound_volume);
	set_music_volume(game->setting->music_volume);
	load_audio(game->audio_man);
}
