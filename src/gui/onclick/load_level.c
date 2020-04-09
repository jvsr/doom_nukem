/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_level.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 19:04:08 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/09 13:37:01 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft/ft_printf.h"
#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "renderer.h"
#include "serializer.h"

void load_level(t_game *game, t_transform *gui)
{
	t_map *map;
	char full_path[PATH_MAX];

	ft_printf("%s\n", gui->gui_elem.button->text->text);
	t_bool focus = get_focus(game);
	if (focus)
		ft_strcpy(full_path, SELECT_CAMPAIGN_PATH);
	else
		ft_strcpy(full_path, SELECT_CUSTOM_PATH);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, gui->gui_elem.button->text->text);
	ft_printf("%s\n", full_path);
	(void)map;
	map = read_map_struct(full_path, game->exec_path);
	delete_map(&game->map);
	load_map(game, map, game->player);
	game->map = map;
	go_to_game(game, gui);
}
