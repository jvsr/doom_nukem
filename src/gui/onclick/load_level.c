/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_level.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 19:04:08 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/08 19:52:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft/ft_printf.h"
#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
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
	t_binary_read *map_bin = new_binary_read(full_path, TRUE, game->exec_path);
	(void)map;
	(void)map_bin;
	// map = read_map(map_bin);
}
