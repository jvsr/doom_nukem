/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_editor_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 16:53:05 by euan          #+#    #+#                 */
/*   Updated: 2020/04/08 17:04:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "game.h"
#include "onclick.h"
#include "gui.h"

void		load_editor_map(t_game *game, t_transform *gui)
{
	t_list *maps;

	(void)game;
	(void)gui;
	create_map_list(game, CUSTOM_PATH);
    maps = read_map_list();
    ft_putstrlst(maps);
    ft_lstdel(&maps, ft_lstdelmem);
}
