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

t_setting	*read_settings(void)
{
	t_setting		*settings;
	t_binary_read	*bin;

	settings = (t_setting*)ft_memalloc(sizeof(t_setting));
	bin = new_binary_read("settings/settings.conf");
	settings->sensitivity = read_float(bin);
	settings->volume = read_float(bin);
	settings->fov = read_short(bin);
	settings->resolution.x = read_int(bin);
	settings->resolution.y = read_int(bin);
	settings->resolution_type = read_int(bin);
	settings->controls.backward = read_int(bin);
	settings->controls.crouch = read_int(bin);
	settings->controls.forward = read_int(bin);
	settings->controls.interact = read_int(bin);
	settings->controls.jump = read_int(bin);
	settings->controls.left = read_int(bin);
	settings->controls.right = read_int(bin);
	settings->controls.shoot = read_int(bin);
	del_binary_read(&bin);
	return (settings);
}
