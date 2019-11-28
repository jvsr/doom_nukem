/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_audio.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 11:16:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/13 16:34:49 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_mem.h"
<<<<<<< HEAD
#include "libft/ft_hash.h"

#include "game.h"
#include "init.h"
#include "setting.h"
=======

#include "game.h"
>>>>>>> 902071b0a5c1d877af5268d2c75fc4a7a48c2f63
#include "audio.h"
#include "error.h"
#include "setting.h"

static void	play_title_song(t_game *game)
{
	fade_in_music(game->audio_man, MUSIC_HIT_N_SMASH, 3500);
}

<<<<<<< HEAD
static void	alloc_hashmaps(t_audio_man *man)
{
	man->sound_map = ft_hashmapnew(SOUND_MAP_SIZE, &INIT_KEYMAP_ALGO);
	if (man->sound_map == NULL)
		error_msg_errno("Failed to allocate hashmap for sound");
	man->music_map = ft_hashmapnew(MUSIC_MAP_SIZE, &INIT_KEYMAP_ALGO);
	if (man->music_map == NULL)
		error_msg_errno("Failed to allocate hashmap for music");
}

=======
>>>>>>> 902071b0a5c1d877af5268d2c75fc4a7a48c2f63
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
<<<<<<< HEAD
	load_audio(game->audio_man);
=======
	load_audio(game);
	play_title_song(game);
>>>>>>> 902071b0a5c1d877af5268d2c75fc4a7a48c2f63
}
