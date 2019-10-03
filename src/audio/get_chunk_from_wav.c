/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_chunk_from_wav.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 11:38:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 11:38:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include <errno.h>
#include "libft/ft_str.h"
#include "audio.h"
#include "error.h"

Mix_Chunk	*get_chunk_from_wav(char *file)
{
	char		*str;
	Mix_Chunk	*chunk;

	str = ft_strjoin(SOUND_EFFECT_LOC, file);
	chunk = Mix_LoadWAV(str);
	if (chunk == NULL)
		error_msg_sdl(ENOENT, "Missing Sound");
	ft_strdel(&str);
	return (chunk);
}
