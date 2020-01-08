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

#include <errno.h>
#include <limits.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_str.h"

#include "game.h"
#include "audio.h"
#include "error.h"

Mix_Chunk	*get_chunk_from_wav(char *file, char const *exec_path)
{
	Mix_Chunk	*chunk;
	char		full_path[PATH_MAX];

	if (exec_path != NULL)
		ft_strcpy(full_path, exec_path);
	else
		full_path[0] = '\0';
	ft_strcat(full_path, SOUND_EFFECT_PATH);
	ft_strcat(full_path, file);
	ft_strcat(full_path, ".wav");
	chunk = Mix_LoadWAV(full_path);
	if (chunk == NULL)
		error_msg_sdl(ENOENT, ft_strformat("Failed to open %s", full_path));
	return (chunk);
}
