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

static void	loadsound(t_game *game)
{
	game->audio_man->effects[0] = get_chunk_from_wav("explosion");
}

static void	loadmusic(t_game *game)
{
	game->audio_man->tracks[0] = get_music_from_mp3("lonely_troutman_ii");
	game->audio_man->tracks[1] = get_music_from_mp3("asking_questions");
	game->audio_man->tracks[2] = get_music_from_mp3("hit_n_smash");
}

void		load_audio(t_game *game)
{
	loadsound(game);
	loadmusic(game);
}
