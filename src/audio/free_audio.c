/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_audio.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 17:08:32 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/30 17:08:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "game.h"
#include "audio.h"
#include "error.h"

static void	free_music(Mix_Music *musics[MUSIC_COUNT])
{
	size_t i;

	i = 0;
	while (i < MUSIC_COUNT)
	{
		Mix_FreeMusic(musics[i]);
		i++;
	}
}

static void	free_sound(Mix_Chunk *chunks[SOUND_COUNT])
{
	size_t i;

	i = 0;
	while (i < SOUND_COUNT)
	{
		Mix_FreeChunk(chunks[i]);
		i++;
	}
}

void		free_audio(t_game *game)
{
	if (game->audio_man == NULL)
		return ;
	free_music(game->audio_man->track);
	free_sound(game->audio_man->effect);
	free(game->audio_man);
	game->audio_man = NULL;
}
