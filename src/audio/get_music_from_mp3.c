/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_music_from_mp3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 14:18:24 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:32:05 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_str.h"

#include "game.h"
#include "audio.h"
#include "error.h"

Mix_Music	*get_music_from_mp3(char *file, char const *exec_path)
{
	Mix_Music	*track;
	char		full_path[PATH_MAX];

	ft_strcpy(full_path, exec_path);
	ft_strcat(full_path, MUSIC_PATH);
	ft_strcat(full_path, file);
	ft_strcat(full_path, ".mp3");
	track = Mix_LoadMUS(full_path);
	if (track == NULL)
		error_msg_sdl(ENOENT, ft_strformat("Failed to open %s", full_path));
	return (track);
}
