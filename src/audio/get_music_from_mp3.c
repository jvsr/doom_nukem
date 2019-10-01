/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_music_from_mp3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 14:18:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/30 14:18:24 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>
#include "libft/ft_str.h"
#include "audio.h"
#include "error.h"

Mix_Music	*get_music_from_mp3(char *file)
{
	char		*str;
	Mix_Music	*track;

	str = ft_strjoin(MUSIC_LOC, file);
	track = Mix_LoadMUS(str);
	if (track == NULL)
		error_msg_sdl(1, "Missing Sound");
	ft_strdel(&str);
	return (track);
}
