/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 13:32:23 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/17 13:32:23 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "gui.h"
#include "setting.h"

void	set_float(float setting, t_transform *location, int precision)
{
	set_elem_text_str(location,
		ft_strformat("%.*f", precision, setting));
}

void	set_int(int setting, t_transform *location)
{
	set_elem_text_str(location,
		ft_strformat("%d", setting));
}

char	*get_resolutiontype(t_resolution_type resolution_type)
{
	if (resolution_type == windowed)
		return ("Windowed");
	else if (resolution_type == fullscreen)
		return ("Fullscreen");
	else if (resolution_type == fullscreen_windowed)
		return ("Borderless");
	return (NULL);
}

void	set_sensitivity(t_setting *setting, t_transform *parent)
{
	set_float(setting->sensitivity,
		get_elem_child(parent, "cursensitivity"),
		1);
}

void	set_music(t_setting *setting, t_transform *parent)
{
	set_float(setting->music_volume * 100,
		get_elem_child(parent, "curmusicvolume"),
		0);
}

void	set_sound(t_setting *setting, t_transform *parent)
{
	set_float(setting->sound_volume * 100,
		get_elem_child(parent, "cursoundvolume"),
		0);
}

void	set_fov(t_setting *setting, t_transform *parent)
{
	set_int(setting->fov,
		get_elem_child(parent, "curfov"));
}

void	set_resolution(t_setting *setting, t_transform *parent)
{
	set_elem_text_str(get_elem_child(parent, "curresolution"),
		ft_strformat("%4d x %-4d", setting->resolution.x, setting->resolution.y));
}

void	set_resolution_type(t_setting *setting, t_transform *parent)
{
	set_elem_text_str(get_elem_child(parent, "curresolutiontype"),
		get_resolutiontype(setting->resolution_type));
}
