/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_level.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 19:04:08 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/14 17:38:46 by jvisser       ########   odam.nl         */
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

void	load_level(t_game *game, t_transform *gui)
{
	t_map	*map;
	char	full_path[PATH_MAX];

	if (ft_strisempty(gui->gui_elem.button->text->text))
		return ;
	if (get_focus(game))
		ft_strcpy(full_path, SELECT_CAMPAIGN_PATH);
	else
		ft_strcpy(full_path, SELECT_CUSTOM_PATH);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, gui->gui_elem.button->text->text);
	map = read_map_struct(full_path, game->exec_path);
	load_map(game, map, game->player);
	go_to_game(game, gui);
}
