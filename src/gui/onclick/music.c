/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   music.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:40:37 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/05 17:22:01 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "audio.h"
#include "onclick.h"
#include "setting.h"

static void	set_restart_music(t_game *game, t_transform *gui)
{
	set_music(game->setting, gui->parent.elem);
	set_music_volume(game->setting->music_volume);
	pause_music();
	resume_music();
}

void		set_music(t_setting *setting, t_transform *parent)
{
	set_float(setting->music_volume * 100,
		get_elem_child(parent, "curmusicvolume"),
		0);
}

void		options_music_volume_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->music_volume, 0.1, 1.0);
	set_restart_music(game, gui);
}

void		options_music_volume_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->music_volume, 0.1, 0.0);
	set_restart_music(game, gui);
}
