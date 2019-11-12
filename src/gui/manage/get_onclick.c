/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_onclick.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 17:27:29 by pholster       #+#    #+#                */
/*   Updated: 2019/10/22 18:02:38 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "onclick.h"
#include "gui_internal.h"

static const t_onclickpair	g_onclicks[] = {
	{"mainmenu_missions", mainmenu_missions},
	{"mainmenu_options", mainmenu_options},
	{"mainmenu_quit", mainmenu_quit},

	{"options_sensitivity_up", options_sensitivity_up},
	{"options_sensitivity_down", options_sensitivity_down},
	{"options_music_volume_up", options_music_volume_up},
	{"options_music_volume_down", options_music_volume_down},
	{"options_sound_volume_up", options_sound_volume_up},
	{"options_sound_volume_down", options_sound_volume_down},
	{"options_fov_up", options_fov_up},
	{"options_fov_down", options_fov_down},
	{"options_resolution_up", options_resolution_up},
	{"options_resolution_down", options_resolution_down},
	{"options_resolutiontype_up", options_resolutiontype_up},
	{"options_resolutiontype_down", options_resolutiontype_down},
	{"options_open_controls", options_open_controls},
	{"options_return", options_return},

	{"missions_focus_campaign", missions_focus_campaign},
	{"missions_focus_custom", missions_focus_custom},
	{"mission_return", mission_return},

	{"confirmation_return", confirmation_return},

	{"controls_set_forward", controls_set_forward},
	{"controls_set_backward", controls_set_backward},
	{"controls_set_left", controls_set_left},
	{"controls_set_right", controls_set_right},
	{"controls_set_shoot", controls_set_shoot},
	{"controls_set_interact", controls_set_interact},
	{"controls_set_crouch", controls_set_crouch},
	{"controls_set_jump", controls_set_jump},
	{"controls_return", controls_return},

	{"restart_game", restart_game},
};

const char	*get_onclick_name(t_onclick *onclick)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;

	if (onclick == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (g_onclicks[i].f != NULL && onclick == g_onclicks[i].f)
			return (g_onclicks[i].name);
		i++;
	}
	return (NULL);
}

t_onclick	*get_onclick_f(const char *name)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;

	if (name == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(name, g_onclicks[i].name))
			return (g_onclicks[i].f);
		i++;
	}
	return (NULL);
}
