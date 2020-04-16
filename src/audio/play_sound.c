/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_sound.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:38:58 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:31:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "audio.h"

void		play_sound(t_audio_man *man, char *const sound)
{
	void	*chunk;

	chunk = get_track_from_map(man->sound_map, sound);
	if (chunk == NULL)
	{
		ft_dprintf(2, "Trying to effect none existing sound '%s'\n", sound);
		return ;
	}
	Mix_PlayChannel(-1, chunk, 0);
}
