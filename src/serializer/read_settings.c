/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_settings.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/18 18:50:28 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/18 18:50:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "setting.h"
#include "serializer.h"
#include "error.h"

t_setting	*read_settings(char const *exec_path)
{
	t_setting		*setting;
	t_binary_read	*bin;

	setting = (t_setting*)ft_memalloc(sizeof(t_setting));
	if (setting == NULL)
		error_msg_errno("Failed to alloc settings");
	bin = new_binary_read("settings/settings.conf", exec_path);
	setting->sensitivity = read_float(bin);
	setting->music_volume = read_float(bin);
	setting->sound_volume = read_float(bin);
	setting->fov = read_short(bin);
	setting->resolution.x = read_int(bin);
	setting->resolution.y = read_int(bin);
	setting->resolution_type = read_int(bin);
	setting->controls.backward = read_int(bin);
	setting->controls.crouch = read_int(bin);
	setting->controls.forward = read_int(bin);
	setting->controls.interact = read_int(bin);
	setting->controls.jump = read_int(bin);
	setting->controls.left = read_int(bin);
	setting->controls.right = read_int(bin);
	setting->controls.shoot = read_int(bin);
	del_binary_read(&bin);
	return (setting);
}
