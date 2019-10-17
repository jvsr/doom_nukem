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

void	set_sensitivity(t_setting *setting, t_transform *parent)
{
	set_float(setting->sensitivity,
		get_elem_child(parent, "cursensitivity"),
		1);
}

void	set_volume(t_setting *setting, t_transform *parent)
{
	set_float(setting->volume * 100,
		get_elem_child(parent, "curvolume"),
		0);
}
