/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:27:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/22 18:40:23 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/ft_str.h"
#include "libft/ft_printf.h" //

#include "gui.h"
#include "game.h"
#include "setting.h"
#include "onclick.h"
#include "gui_config.h"
#include "serializer.h"

#include "audio.h"

void	incr_float_max(float *loc, float incr, float max)
{
	*loc += incr;
	if (*loc > max)
		*loc = max;
}

void	decr_float_min(float *loc, float decr, float min)
{
	*loc -= decr;
	if (*loc < min)
		*loc = min;
}

void	incr_uint16_max(t_uint16 *loc, t_uint16 incr, t_uint16 max)
{
	*loc += incr;
	if (*loc > max)
		*loc = max;
}

void	decr_uint16_min(t_uint16 *loc, t_uint16 decr, t_uint16 min)
{
	*loc -= decr;
	if (*loc < min)
		*loc = min;
}

void	incr_game_resolution(SDL_Point *resolution)
{
	if (resolution->x == 1680 && resolution->y == 1050)
	{
		resolution->x = 1920;
		resolution->y = 1080;
	}
	else if (resolution->x == 1280 && resolution->y == 768)
	{
		resolution->x = 1680;
		resolution->y = 1050;
	}
	else if (resolution->x == 1280 && resolution->y == 720)
	{
		resolution->x = 1280;
		resolution->y = 768;
	}
	else if (resolution->x == 1024 && resolution->y == 768)
	{
		resolution->x = 1280;
		resolution->y = 720;
	}
	else if (resolution->x == 960 && resolution->y == 640)
	{
		resolution->x = 1024;
		resolution->y = 768;
	}
}

void	decr_game_resolution(SDL_Point *resolution)
{
	if (resolution->x == 1920 && resolution->y == 1080)
	{
		resolution->x = 1680;
		resolution->y = 1050;
	}
	else if (resolution->x == 1680 && resolution->y == 1050)
	{
		resolution->x = 1280;
		resolution->y = 768;
	}
	else if (resolution->x == 1280 && resolution->y == 768)
	{
		resolution->x = 1280;
		resolution->y = 720;
	}
	else if (resolution->x == 1280 && resolution->y == 720)
	{
		resolution->x = 1024;
		resolution->y = 768;
	}
	else if (resolution->x == 1024 && resolution->y == 768)
	{
		resolution->x = 960;
		resolution->y = 640;
	}
}

void	incr_game_resolution_type(t_resolution_type *resolution_type)
{
	if (*resolution_type == windowed)
		*resolution_type = fullscreen_windowed;
	else if (*resolution_type == fullscreen_windowed)
		*resolution_type = fullscreen;
	else if (*resolution_type == fullscreen)
		*resolution_type = windowed;
}

void	decr_game_resolution_type(t_resolution_type *resolution_type)
{
	if (*resolution_type == fullscreen)
		*resolution_type = fullscreen_windowed;
	else if (*resolution_type == fullscreen_windowed)
		*resolution_type = windowed;
	else if (*resolution_type == windowed)
		*resolution_type = fullscreen;
}

void	options_sensitivity_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	print_elem(gui, FALSE);
	incr_float_max(&game->setting->sensitivity, 0.1, 3.0);
	set_sensitivity(game->setting, gui->parent.elem);
}

void	options_sensitivity_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->sensitivity, 0.1, 0.1);
	set_sensitivity(game->setting, gui->parent.elem);
}

void	options_music_volume_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->music_volume, 0.1, 1.0);
	set_music(game->setting, gui->parent.elem);
	set_music_volume(game->setting->music_volume);
	pause_music();
	resume_music();
}

void	options_music_volume_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->music_volume, 0.1, 0.0);
	set_music(game->setting, gui->parent.elem);
	set_music_volume(game->setting->music_volume);
	pause_music();
	resume_music();
}

void	options_sound_volume_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_float_max(&game->setting->sound_volume, 0.1, 1.0);
	set_sound(game->setting, gui->parent.elem);
	set_sound_volume(game->setting->sound_volume);
	pause_all_sounds();
	resume_all_sounds();
}

void	options_sound_volume_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_float_min(&game->setting->sound_volume, 0.1, 0.0);
	set_sound(game->setting, gui->parent.elem);
	set_sound_volume(game->setting->sound_volume);
	pause_all_sounds();
	resume_all_sounds();
}

void	options_fov_up(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	incr_uint16_max(&game->setting->fov, 5, 110);
	set_fov(game->setting, gui->parent.elem);
}

void	options_fov_down(t_game *game, t_transform *gui)
{
	game->setting->changed = TRUE;
	decr_uint16_min(&game->setting->fov, 5, 45);
	set_fov(game->setting, gui->parent.elem);
}

void	options_resolution_up(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	incr_game_resolution(&game->setting->resolution);
	set_resolution(game->setting, gui->parent.elem);
}

void	options_resolution_down(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	decr_game_resolution(&game->setting->resolution);
	set_resolution(game->setting, gui->parent.elem);
}

void	options_resolutiontype_up(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	incr_game_resolution_type(&game->setting->resolution_type);
	set_resolution_type(game->setting, gui->parent.elem);
}

void	options_resolutiontype_down(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	decr_game_resolution_type(&game->setting->resolution_type);
	set_resolution_type(game->setting, gui->parent.elem);
}

void	add_confirmation(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "confirmationmenu");
	overlay = get_gui_child(game->ui, "confirmationoverlay");
	set_elem_show_clickable(menu, TRUE);
	set_elem_show_clickable(overlay, TRUE);
}

void	remove_confirmation(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "confirmationmenu");
	overlay = get_gui_child(game->ui, "confirmationoverlay");
	set_elem_show_clickable(menu, FALSE);
	set_elem_show_clickable(overlay, FALSE);
}

void	remove_options(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "optionsmenu");
	overlay = get_gui_child(game->ui, "optionsoverlay");
	set_elem_show_clickable(menu, FALSE);
	set_elem_show_clickable(overlay, FALSE);
}

void	options_return(t_game *game, t_transform *gui)
{
	(void)gui;
	if (game->setting->changed == TRUE || game->setting->confirm == TRUE)
	{
		write_settings(game->setting);
		if (game->setting->confirm == TRUE)
			add_confirmation(game);
	}
	if (game->setting->confirm == FALSE)
		remove_options(game);
	game->setting->changed = FALSE;
	game->setting->confirm = FALSE;
}

void	confirmation_return(t_game *game, t_transform *gui)
{
	(void)gui;
	remove_confirmation(game);
	remove_options(game);
}

void	restart_game(t_game *game, t_transform *gui)
{
	char *newargv[] = { "foo", NULL };

	(void)gui;
	(void)game;
	execve("./doom-nukem", newargv, NULL);
}

void	options_open_controls(t_game *game, t_transform *gui)
{
	t_transform	*controls;

	(void)gui;
	controls = get_gui_child(game->ui, "controls");
	set_elem_show_clickable(controls, TRUE);
}

/*
**	* Supported Window Dimensions
**	* 1920 x 1080
**	* 1680 x 1050
**	* 1280 x 768
**	* 1280 x 720
**	* 1024 x 768
**	* 960 x 640
*/
