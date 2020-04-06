/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hudmusic.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 21:08:25 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:14:21 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "onclick.h"
#include "setting.h"

static void	set_restart_hudmusic(t_game *game, t_transform *gui)
{
	set_hudmusic(game->setting, gui->parent.elem);
	set_music_volume(game->setting->music_volume);
	pause_music();
	resume_music();
}

void		set_hudmusic(t_setting *setting, t_transform *parent)
{
	set_float(setting->music_volume * 100,
		get_elem_child(parent, "curHudMusicVolume"),
		0);
}

void		options_hud_music_volume_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->music_volume, 0.1, 1.0);
	set_restart_hudmusic(game, gui);
}

void		options_hud_music_volume_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->music_volume, 0.1, 0.0);
	set_restart_hudmusic(game, gui);
}
