/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_settings.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/18 18:29:53 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:52:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "game.h"
#include "setting.h"
#include "serializer.h"

void	write_settings(t_setting *settings, char const *exec_path)
{
	t_binary *bin;

	bin = new_binary();
	add_float(settings->sensitivity, bin);
	add_float(settings->music_volume, bin);
	add_float(settings->sound_volume, bin);
	add_short(settings->fov, bin);
	add_int(settings->resolution.x, bin);
	add_int(settings->resolution.y, bin);
	add_int(settings->resolution_type, bin);
	add_int(settings->controls.backward, bin);
	add_int(settings->controls.crouch, bin);
	add_int(settings->controls.forward, bin);
	add_int(settings->controls.interact, bin);
	add_int(settings->controls.jump, bin);
	add_int(settings->controls.left, bin);
	add_int(settings->controls.right, bin);
	add_int(settings->controls.shoot, bin);
	finish_bin(bin);
	write_struct("settings/settings.conf", bin, exec_path);
	del_binary(&bin);
}
