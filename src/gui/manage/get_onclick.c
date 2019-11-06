/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_onclick.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 17:27:29 by pholster       #+#    #+#                */
/*   Updated: 2019/11/06 17:33:09 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "table.h"
#include "error.h"
#include "onclick.h"
#include "gui_internal.h"

#define TABLE_SIZE 22

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

	{"restart_game", restart_game},
};

static void		fill_gui_onclick_table_0_9(t_tablepair *gui_onclicks)
{
	gui_onclicks[0] = (t_tablepair){"mainmenu_missions",
									mainmenu_missions};
	gui_onclicks[1] = (t_tablepair){"mainmenu_options",
									mainmenu_options};
	gui_onclicks[2] = (t_tablepair){"mainmenu_quit",
									mainmenu_quit};
	gui_onclicks[3] = (t_tablepair){"options_sensitivity_up",
									options_sensitivity_up};
	gui_onclicks[4] = (t_tablepair){"options_sensitivity_down",
									options_sensitivity_down};
	gui_onclicks[5] = (t_tablepair){"options_music_volume_up",
									options_music_volume_up};
	gui_onclicks[6] = (t_tablepair){"options_sound_volume_up",
									options_sound_volume_up};
	gui_onclicks[7] = (t_tablepair){"options_sound_volume_down",
									options_sound_volume_down};
	gui_onclicks[8] = (t_tablepair){"options_music_volume_down",
									options_music_volume_down};
	gui_onclicks[9] = (t_tablepair){"options_fov_up",
									options_fov_up};
}

static void		fill_gui_onclick_table_10_19(t_tablepair *gui_onclicks)
{
	gui_onclicks[10] = (t_tablepair){"options_fov_down",
									options_fov_down};
	gui_onclicks[11] = (t_tablepair){"options_resolution_up",
									options_resolution_up};
	gui_onclicks[12] = (t_tablepair){"options_resolution_down",
									options_resolution_down};
	gui_onclicks[13] = (t_tablepair){"options_resolutiontype_up",
									options_resolutiontype_up};
	gui_onclicks[14] = (t_tablepair){"options_resolutiontype_down",
									options_resolutiontype_down};
	gui_onclicks[15] = (t_tablepair){"options_open_controls",
									options_open_controls};
	gui_onclicks[16] = (t_tablepair){"options_return",
									options_return};
	gui_onclicks[17] = (t_tablepair){"missions_focus_campaign",
									missions_focus_campaign};
	gui_onclicks[18] = (t_tablepair){"missions_focus_custom",
									missions_focus_custom};
	gui_onclicks[19] = (t_tablepair){"mission_return",
									mission_return};
}

static void		fill_gui_onclick_table_20_29(t_tablepair *gui_onclicks)
{
	gui_onclicks[20] = (t_tablepair){"confirmation_return",
									confirmation_return};
	gui_onclicks[21] = (t_tablepair){"restart_game",
									restart_game};
}

t_tablepair	*create_gui_onclick_table(void)
{
	t_tablepair	*gui_onclicks;

	gui_onclicks = (t_tablepair*)ft_memalloc(sizeof(t_tablepair) * TABLE_SIZE);
	if (gui_onclicks == NULL)
		error_msg_errno("Failed to allocate gui onclick table");
	fill_gui_onclick_table_0_9(gui_onclicks);
	fill_gui_onclick_table_10_19(gui_onclicks);
	fill_gui_onclick_table_20_29(gui_onclicks);

	return (gui_onclicks);
}

const char	*get_onclick_name(t_onclick *onclick)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;
	t_tablepair		*gui_onclicks;

	if (onclick == NULL)
		return (NULL);
	i = 0;
	gui_onclicks = create_gui_onclick_table();
	return (NULL);
}

t_onclick	*get_onclick_f(const char *name)
{
	t_onclick		*result;
	t_tablepair		*gui_onclicks;

	if (name == NULL)
		return (NULL);
	gui_onclicks = create_gui_onclick_table();
	result = find_tablepair_value(gui_onclicks, TABLE_SIZE, name);
	free(gui_onclicks);
	return (result);
}
