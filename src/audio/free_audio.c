/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_audio.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 17:08:32 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:32:11 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_hash.h"

#include "game.h"
#include "audio.h"
#include "error.h"

static void	del_sound(void *sound)
{
	Mix_FreeChunk((Mix_Chunk*)sound);
}

static void	free_sound(t_hashmap *sound_map)
{
	ft_hashmapdel(sound_map, del_sound);
}

static void	del_music(void *music)
{
	Mix_FreeMusic((Mix_Music*)music);
}

static void	free_music(t_hashmap *music_map)
{
	ft_hashmapdel(music_map, del_music);
}

void		free_audio(t_game *game)
{
	if (game->audio_man == NULL)
		return ;
	free_sound(game->audio_man->sound_map);
	free_music(game->audio_man->music_map);
	free(game->audio_man);
	game->audio_man = NULL;
}
