/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mission.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/22 16:13:28 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:36:44 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/ft_num.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"

static void	remove_mission(t_game *game)
{
	t_transform	*elem;

	elem = get_gui_child(game->ui, "missionsMenu");
	set_elem_show_clickable(elem, FALSE);
	elem = get_gui_child(game->ui, "missionsOverlay");
	set_elem_show_clickable(elem, FALSE);
	elem = get_gui_child(game->ui, "missionsCampaignButton");
	set_elem_show_clickable(elem, FALSE);
	elem = get_gui_child(game->ui, "missionsCustombutton");
	set_elem_show_clickable(elem, FALSE);
}

void		set_page_number(t_game *game)
{
	char		*str;
	t_transform	*page;

	page = get_gui_child(game->ui, "missionPage");
	str = ft_itoa(game->ui->mission_page);
	set_elem_text_str(page, str);
	free(str);
}

void		mission_return(t_game *game, t_transform *gui)
{
	(void)gui;
	remove_mission(game);
	remove_maps(game);
}
