/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_resolution_type.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:50:46 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 15:51:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "setting.h"

static char	*get_resolution_type(t_resolution_type resolution_type)
{
	if (resolution_type == windowed)
		return ("Windowed");
	else if (resolution_type == fullscreen)
		return ("Fullscreen");
	else if (resolution_type == borderless)
		return ("Borderless");
	return (NULL);
}

void		set_resolution_type(t_setting *setting, t_transform *parent)
{
	t_transform	*elem;
	char		*text;

	elem = get_elem_child(parent, "curresolutiontype");
	text = get_resolution_type(setting->resolution_type);
	set_elem_text_str(elem, text);
}
