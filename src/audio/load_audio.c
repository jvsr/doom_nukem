/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_audio.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 17:28:18 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 17:28:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "game.h"
#include "audio.h"
#include "error.h"

static void	loadeffects(t_game *game)
{
	char	**files;
	size_t	index;

	files = (char *[]){
		"explosion.wav"
	};
	index = 0;
	while (index < SOUND_COUNT)
	{
		game->a_manager->effects[index] = get_chunk_from_wav(files[index]);
		index++;
	}
}

static void	loadmusic(t_game *game)
{
	char	**files;
	size_t	index;

	files = (char *[]){
		"asking_questions.mp3"
	};
	index = 0;
	while (index < SOUND_COUNT)
	{
		game->a_manager->tracks[index] = get_music_from_mp3(files[index]);
		index++;
	}
}

void		load_audio(t_game *game)
{
	int support;

	if (Mix_OpenAudio(AUDIO_FREQ, AUDIO_S16SYS, AUDIO_CHANNELS, AUDIO_BUFFER)
		!= 0)
		error_msg(SDL_GetError(), 1, "Failed to init Audio Mixer");
	support = Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
	if (!(support & MIX_INIT_MP3))
		error_msg(SDL_GetError(), 1, "Failed to init Audio Mixer");
	loadeffects(game);
	loadmusic(game);
}
