/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_onclick.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 17:27:29 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/09 12:27:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "onclick.h"
#include "gui_internal.h"
#include "table.h"

static t_tablepair const	g_onclicks[] = {
	{"mainmenu_missions", mainmenu_missions},
	{"mainmenu_options", mainmenu_options},
	{"mainmenu_mapeditor", mainmenu_mapeditor},
	{"mainmenu_quit", mainmenu_quit},

	{"map_editor_select_return", map_editor_select_return},
	{"map_editor_select_new", map_editor_select_new},
	{"load_editor_map", load_editor_map},
	{"load_editor_map_ok", load_editor_map_ok},
	{"load_editor_map_next", load_editor_map_next},
	{"load_editor_map_prv", load_editor_map_prv},
	{"load_editor_map_cancel", load_editor_map_cancel},

	{"map_editor_object_next", map_editor_object_next},
	{"map_editor_object_prv", map_editor_object_prv},
	{"map_editor_object_select", map_editor_object_select},
	{"map_editor_confirmation_return", map_editor_confirmation_return},
	{"map_editor_remove_confirmation", map_editor_remove_confirmation},
	{"map_editor_object_next", map_editor_object_next},
	{"map_editor_object_prv", map_editor_object_prv},
	{"map_editor_object_select", map_editor_object_select},
	{"save_map", save_map},

	{"options_sensitivity_up", options_sensitivity_up},
	{"options_hud_sensitivity_up", options_hud_sensitivity_up},
	{"options_sensitivity_down", options_sensitivity_down},
	{"options_hud_sensitivity_down", options_hud_sensitivity_down},
	{"options_music_volume_up", options_music_volume_up},
	{"options_hud_music_volume_up", options_hud_music_volume_up},
	{"options_music_volume_down", options_music_volume_down},
	{"options_hud_music_volume_down", options_hud_music_volume_down},
	{"options_sound_volume_up", options_sound_volume_up},
	{"options_hud_sound_volume_up", options_hud_sound_volume_up},
	{"options_sound_volume_down", options_sound_volume_down},
	{"options_hud_sound_volume_down", options_hud_sound_volume_down},
	{"options_fov_up", options_fov_up},
	{"options_hud_fov_up", options_hud_fov_up},
	{"options_fov_down", options_fov_down},
	{"options_hud_fov_down", options_hud_fov_down},
	{"options_resolution_up", options_resolution_up},
	{"options_resolution_down", options_resolution_down},
	{"options_resolutiontype_up", options_resolutiontype_up},
	{"options_resolutiontype_down", options_resolutiontype_down},
	{"options_open_controls", options_open_controls},
	{"options_return", options_return},
	{"hudoptions_return", hudoptions_return},
	{"hud_diedreturn", hud_diedmainmenu},

	{"missions_left_page", missions_left_page},
	{"missions_right_page", missions_right_page},
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

	{"load_level", load_level},

	{"restart_game", restart_game},
	{"go_to_game", go_to_game}
};

char const	*get_onclick_name(t_onclick *onclick)
{
	size_t const	table_size = sizeof(g_onclicks) / sizeof(t_tablepair);

	if (onclick == NULL)
		return (NULL);
	return (find_tablepair_id(g_onclicks, table_size, onclick));
}

t_onclick	*get_onclick_f(const char *name)
{
	size_t const	table_size = sizeof(g_onclicks) / sizeof(t_tablepair);

	if (name == NULL)
		return (NULL);
	return (find_tablepair_value(g_onclicks, table_size, name));
}
