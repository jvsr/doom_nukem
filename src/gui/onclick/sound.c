/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sound.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:42:09 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "onclick.h"
#include "setting.h"

void	set_sound(t_setting *setting, t_transform *parent)
{
	set_float(setting->sound_volume * 100,
		get_elem_child(parent, "curSoundVolume"),
		0);
}

void	options_sound_volume_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->sound_volume, 0.1, 1.0);
	set_sound(game->setting, gui->parent.elem);
	set_sound_volume(game->setting->sound_volume);
	pause_all_sound();
	resume_all_sound();
}

void	options_sound_volume_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->sound_volume, 0.1, 0.0);
	set_sound(game->setting, gui->parent.elem);
	set_sound_volume(game->setting->sound_volume);
	pause_all_sound();
	resume_all_sound();
}
