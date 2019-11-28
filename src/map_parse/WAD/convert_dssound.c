/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_dssound.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 09:16:47 by pholster       #+#    #+#                */
/*   Updated: 2019/11/28 09:16:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"
#include "libft/ft_mem.h"

#include "wad.h"
#include "game.h"
#include "error.h"
#include "audio.h"

#define WAV_HEADER_SIZE 44
#define DSSOUND_CHANNELS 1

static void			del_dssound(t_wad_dssound *sound, t_uint8 *wav)
{
	ft_memdel((void **)&sound->sample);
	ft_memdel((void **)&sound->name);
	ft_memdel((void **)&sound);
	ft_memdel((void **)&wav);
}

static t_uint8		*alloc_wav(size_t size)
{
	t_uint8	*wav;

	wav = (t_uint8 *)ft_memalloc(sizeof(t_uint8) * (WAV_HEADER_SIZE + size));
	if (wav == NULL)
		error_msg_errno("Failed to alloc dssound to wav header");
	return (wav);
}

static void			addnum(SDL_RWops *rw, t_uint32 num, size_t size)
{
	rw->write(rw, &num, size, 1);
}

static SDL_RWops	*format_wav(t_uint8 *wav, t_wad_dssound *sound, size_t size)
{
	SDL_RWops	*rw;

	rw = SDL_RWFromMem(wav, (WAV_HEADER_SIZE + size));
	if (rw == NULL)
		error_msg_sdl(21, "Failed to alloc RWops for dssound");
	rw->write(rw, "RIFF", sizeof(t_uint32), 1);
	addnum(rw, 36 + size, sizeof(t_uint32));
	rw->write(rw, "WAVE", sizeof(t_uint32), 1);
	rw->write(rw, "fmt ", sizeof(t_uint32), 1);
	addnum(rw, 16, sizeof(t_uint32));
	addnum(rw, 1, sizeof(t_uint16));
	addnum(rw, DSSOUND_CHANNELS, sizeof(t_uint16));
	rw->write(rw, &sound->sample_rate, sizeof(t_uint32), 1);
	addnum(rw, sound->sample_rate * DSSOUND_CHANNELS, sizeof(t_uint32));
	addnum(rw, DSSOUND_CHANNELS, sizeof(t_uint16));
	addnum(rw, 8, sizeof(t_uint16));
	rw->write(rw, "data", sizeof(t_uint32), 1);
	rw->write(rw, &size, sizeof(t_uint32), 1);
	rw->write(rw, sound->sample, size, 1);
	rw->seek(rw, 0, RW_SEEK_SET);
	return (rw);
}

void				convert_dssound(t_wad *wad, t_game *game)
{
	Mix_Chunk		*chunk;
	t_wad_dssound	*sound;
	t_wad_dssound	*next;
	t_uint8			*wav;
	size_t			size;

	sound = wad->general->dssound;
	wad->general->dssound = NULL;
	while (sound != NULL)
	{
		size = sound->sample_count * DSSOUND_CHANNELS;
		wav = alloc_wav(size);
		chunk = Mix_LoadWAV_RW(format_wav(wav, sound, size), TRUE);
		if (chunk == NULL)
			ft_dprintf(2, "Invalid sound file '%s'\n", sound->name);
		else
			add_track_to_map(game->audio_man->sound_map, chunk, sound->name);
		next = sound->next;
		del_dssound(sound, wav);
		sound = next;
	}
}
