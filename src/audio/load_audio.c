/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_audio.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 17:28:18 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:52 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "audio.h"

void		load_audio(t_audio_man *man, char const *exec_path)
{
	load_sound(man->sound_map, exec_path);
	load_music(man->music_map, exec_path);
}
