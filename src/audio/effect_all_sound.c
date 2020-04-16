/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   effect_all_sound.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:34:06 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:32:24 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "audio.h"

void	effect_all_sound(int (*func)(int))
{
	int	index;

	index = 0;
	while (index < AUDIO_MAX_CHUNKS)
	{
		func(index);
		index++;
	}
}
