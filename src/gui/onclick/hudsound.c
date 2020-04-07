/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hudsound.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:14:03 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:14:17 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "onclick.h"
#include "setting.h"

void	set_hudsound(t_setting *setting, t_transform *parent)
{
	set_float(setting->sound_volume * 100,
		get_elem_child(parent, "curHudSoundVolume"),
		0);
}

void	options_hud_sound_volume_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->sound_volume, 0.1, 1.0);
	set_hudsound(game->setting, gui->parent.elem);
	set_sound_volume(game->setting->sound_volume);
	pause_all_sound();
	resume_all_sound();
}

void	options_hud_sound_volume_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->sound_volume, 0.1, 0.0);
	set_hudsound(game->setting, gui->parent.elem);
	set_sound_volume(game->setting->sound_volume);
	pause_all_sound();
	resume_all_sound();
}
