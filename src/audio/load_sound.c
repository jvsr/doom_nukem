/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sound.c                                       :+:    :+:            */
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

static void	addsound(t_hashmap *sound_map,
									char *const name, char const *exec_path)
{
	add_track_to_map(sound_map, get_chunk_from_wav(name, exec_path), name);
}

void		load_sound(t_hashmap *sound_map, char const *exec_path)
{
	addsound(sound_map, "explosion", exec_path);
}
