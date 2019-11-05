/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resolution.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:42:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 15:39:58 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "setting.h"

/*
**	* Supported Window Dimensions
**	* 1920 x 1080
**	* 1680 x 1050
**	* 1280 x 768
**	* 1280 x 720
**	* 1024 x 768
**	* 960 x 640
*/

void		set_resolution(t_setting *setting, t_transform *parent)
{
	t_transform	*elem;
	char		*text;

	elem = get_elem_child(parent, "curresolution");
	text = ft_strformat("%4d x %-4d",
		setting->resolution.x,
		setting->resolution.y);
	set_elem_text_str(elem, text);
	free(text);
}

static void	incr_game_resolution(SDL_Point *resolution)
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

static void	decr_game_resolution(SDL_Point *resolution)
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

void		options_resolution_up(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	incr_game_resolution(&game->setting->resolution);
	set_resolution(game->setting, gui->parent.elem);
}

void		options_resolution_down(t_game *game, t_transform *gui)
{
	game->setting->confirm = TRUE;
	decr_game_resolution(&game->setting->resolution);
	set_resolution(game->setting, gui->parent.elem);
}
