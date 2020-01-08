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

static void	loadsound(Mix_Chunk **effects, char const *exec_path)
{
	effects[0] = get_chunk_from_wav("explosion", exec_path);
}

static void	loadmusic(Mix_Music **tracks, char const *exec_path)
{
	tracks[0] = get_music_from_mp3("lonely_troutman_ii", exec_path);
	tracks[1] = get_music_from_mp3("asking_questions", exec_path);
	tracks[2] = get_music_from_mp3("hit_n_smash", exec_path);
}

void		load_audio(t_game *game)
{
	loadsound(game->audio_man->effects, game->exec_path);
	loadmusic(game->audio_man->tracks, game->exec_path);
}
