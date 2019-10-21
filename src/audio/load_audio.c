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
#include "libft/ft_mem.h"
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
		game->audio_man->effects[index] = get_chunk_from_wav(files[index]);
		index++;
	}
}

static void	loadmusic(t_game *game)
{
	char	**files;
	size_t	index;

	files = (char *[]){
		"lonely_troutman_ii.mp3",
		"asking_questions.mp3",
		"hit_n_smash.mp3",
	};
	index = 0;
	while (index < MUSIC_COUNT)
	{
		game->audio_man->tracks[index] = get_music_from_mp3(files[index]);
		index++;
	}
}

void		load_audio(t_game *game)
{
	loadeffects(game);
	loadmusic(game);
}
