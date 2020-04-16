/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_sound.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 17:28:18 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/09 11:59:49 by euan          ########   odam.nl         */
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
	addsound(sound_map, "shotgun", exec_path);
	addsound(sound_map, "singleshot", exec_path);
	addsound(sound_map, "window_shatter", exec_path);
	addsound(sound_map, "ammo_pickup", exec_path);
	addsound(sound_map, "key_pickup", exec_path);
	addsound(sound_map, "health_pickup", exec_path);
	addsound(sound_map, "button_ui", exec_path);
	addsound(sound_map, "door_unlock", exec_path);
}
