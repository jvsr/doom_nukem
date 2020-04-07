/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 13:35:31 by euan          #+#    #+#                 */
/*   Updated: 2020/04/07 13:18:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/ft_list.h"
#include "map_editor.h"
#include "serializer.h"
#include "rinfo.h"
#include "game.h"
#include "gui.h"

void		save_map(t_game *game, t_transform *gui)
{
	// t_map	*map;

	(void)gui;
	if (ft_lstlen(game->editor_map->walls) < 3)
		return ((void)ft_printf("Map Does Not Contain Enough Walls\n"));
	map_editor_clean(game->editor_map);
	printf("%zu\n", ft_lstlen(game->editor_map->sectors));
}
