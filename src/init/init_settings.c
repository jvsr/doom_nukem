/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_settings.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:45:10 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:46:21 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <SDL2/SDL_events.h>
#include <math.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "libft/ft_num.h"

#include "game.h"
#include "setting.h"
#include "init.h"
#include "error.h"
#include "serializer.h"

static int		open_file(char const *exec_path)
{
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, exec_path);
	ft_strcat(full_path, SETTINGS_PATH);
	ft_strcat(full_path, "settings.conf");
	return (open(full_path, O_RDONLY));
}

static void		init_controls(t_setting *settings)
{
	settings->controls.forward = SDLK_w;
	settings->controls.backward = SDLK_s;
	settings->controls.left = SDLK_a;
	settings->controls.right = SDLK_d;
	settings->controls.interact = SDLK_e;
	settings->controls.shoot = SDL_BUTTON_LEFT;
	settings->controls.jump = SDLK_SPACE;
	settings->controls.crouch = SDLK_LCTRL;
}

void			init_settings(t_game *game)
{
	int			fd;
	t_setting	*setting;

	fd = open_file(game->exec_path);
	if (fd != -1)
		game->setting = read_settings(game->exec_path);
	else
	{
		setting = (t_setting *)ft_memalloc(sizeof(t_setting));
		if (setting == NULL)
			error_msg_errno("Failed to alloc settings");
		setting->sensitivity = 1.0;
		setting->music_volume = 0.8;
		setting->sound_volume = 0.8;
		setting->fov = 45;
		setting->resolution.x = INIT_WIDTH;
		setting->resolution.y = INIT_HEIGHT;
		setting->resolution_type = fullscreen;
		game->setting = setting;
		init_controls(setting);
	}
	close(fd);
	game->setting->fov = ft_constrain(game->setting->fov, MIN_FOV, MAX_FOV);
}
