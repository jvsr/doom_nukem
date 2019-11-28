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

#include "libft/ft_printf.h" //
#include "libft/ft_mem.h" //
#include "libft/ft_str.h" //

#include "wad.h"
#include "game.h"

#include "serializer.h" //

static void		print_wav(t_uint8 *wav)
{
	char *chunk_id = ft_strndup((char *)wav, 4);
	int chunk_size = *((int *)ft_memdup(wav + 4, 4));
	char *format = ft_strndup((char *)wav + 8, 4);
	ft_printf("chunk_id = %s\nchunk_size = %d\nformat = %s\n", chunk_id, chunk_size, format);
	ft_printf("\n");

	char *subchunk1_id = ft_strndup((char *)wav + 12, 4);
	int subchunk1_size = *((int *)ft_memdup(wav + 16, 4));;
	ft_printf("subchunk1_id = %s\nsubchunk1_size = %d\n", subchunk1_id, subchunk1_size);
	ft_printf("\n");

	int audio_format = *((int *)ft_memdup(wav + 20, 2));
	int num_channels = *((int *)ft_memdup(wav + 22, 2));
	int sample_rate = *((int *)ft_memdup(wav + 24, 4));
	int byte_rate = *((int *)ft_memdup(wav + 28, 4));
	int block_align = *((int *)ft_memdup(wav + 32, 2));
	int bits_per_sample = *((int *)ft_memdup(wav + 34, 2));
	ft_printf("audio_format = %d\nnum_channels = %d\nsample_rate = %d\nbyte_rate = %d\nblock_align = %d\nbits_per_sample = %d\n", audio_format, num_channels, sample_rate, byte_rate, block_align, bits_per_sample);
	ft_printf("\n");

	char *subchunk2_id = ft_strndup((char *)wav + 36, 4);
	int subchunk2_size = *((int *)ft_memdup(wav + 40, 4));
	ft_printf("subchunk2_id = %s\nsubchunk2_size = %d\n", subchunk2_id, subchunk2_size);

	int	i = 0;
	int num_sample = subchunk2_size / block_align;
	// t_uint8 *data = ft_memdup(wav + 44, num_sample * block_align);
	// while (i < num_sample) {
	// 	ft_printf("%x ", *((int *)ft_memdup(data + (i * block_align), block_align)));
	// 	if ((i % 8) == 0)
	// 		ft_printf("\n");
	// 	i++;
	// }
	ft_printf("\n");
}

// static t_uint8	*format_wav(t_wad_dssound *dssound)
// {

// }

void			convert_dssound(t_wad *wad, t_game *game)
{
	t_wad_dssound	*sound;
	// t_uint8			*wav;

	(void)game;
	sound = wad->general->dssound;
	ft_printf("explosion\n");
	print_wav(new_binary_read("explosion.wav", TRUE)->bytes);
	// while (sound != NULL)
	// {
		// wav = format_wav(sound);
		// ft_printf("%s\n", sound->name);
		// print_wav(wav);
	// 	sound = sound->next;
	// }
}
