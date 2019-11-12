/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_settings.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:53:44 by pholster       #+#    #+#                */
/*   Updated: 2019/11/12 14:53:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "game.h"
#include "setting.h"
#include "init.h"
#include "error.h"
#include "serializer.h"

static int	open_file(void)
{
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, g_doom_dir);
	ft_strcat(full_path, SETTINGS_PATH);
	ft_strcat(full_path, "settings.conf");
	return (open(full_path, O_RDONLY));
}

void		init_settings(t_game *game)
{
	int			fd;
	t_setting	*setting;

	fd = open_file();
	if (fd == -1)
	{
		setting = (t_setting *)ft_memalloc(sizeof(t_setting));
		if (setting == NULL)
			error_msg_errno("Failed to alloc settings");
		setting->sensitivity = 1.0;
		setting->music_volume = 0.8;
		setting->sound_volume = 0.8;
		setting->fov = 75;
		setting->resolution.x = INIT_WIDTH;
		setting->resolution.y = INIT_HEIGHT;
		setting->resolution_type = fullscreen;
		game->setting = setting;
		return ;
	}
	close(fd);
	game->setting = read_settings();
}
