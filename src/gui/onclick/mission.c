/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mission.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/22 16:13:28 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/20 17:06:15 by jvisser       ########   odam.nl         */
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

	elem = get_gui_child(game->ui, "missionsmenu");
	set_elem_show_clickable(elem, FALSE);
	elem = get_gui_child(game->ui, "missionsoverlay");
	set_elem_show_clickable(elem, FALSE);
	elem = get_gui_child(game->ui, "missionscampaignbutton");
	set_elem_show_clickable(elem, FALSE);
	elem = get_gui_child(game->ui, "missionscustombutton");
	set_elem_show_clickable(elem, FALSE);
}

static void	switch_focus(t_transform *focus, t_transform *no_focus)
{
	set_elem_layer(focus, 4);
	set_elem_layer(no_focus, 3);
	set_elem_text_color(focus, (SDL_Color){227, 227, 227, 255});
	set_elem_text_color(no_focus, (SDL_Color){102, 102, 102, 255});
}

void		set_page_number(t_game *game)
{
	char		*str;
	t_transform	*page;

	page = get_gui_child(game->ui, "missionpage");
	str = ft_itoa(game->ui->mission_page);
	set_elem_text_str(page, str);
	free(str);
}

void		missions_left_page(t_game *game, t_transform *gui)
{
	(void)gui;
	if (game->ui->mission_page > 0)
		game->ui->mission_page--;
	set_page_number(game);
	remove_maps(game);
	load_missions(game);
}

void		missions_right_page(t_game *game, t_transform *gui)
{
	(void)gui;
	game->ui->mission_page++;
	set_page_number(game);
	remove_maps(game);
	load_missions(game);
}

void		missions_focus_campaign(t_game *game, t_transform *gui)
{
	t_transform	*campaign;
	t_transform	*custom;

	(void)gui;
	campaign = get_gui_child(game->ui, "missionscampaignbutton");
	custom = get_gui_child(game->ui, "missionscustombutton");
	switch_focus(campaign, custom);
	game->ui->mission_page = 0;
	set_page_number(game);
	remove_maps(game);
	load_missions(game);
}

void		missions_focus_custom(t_game *game, t_transform *gui)
{
	t_transform	*campaign;
	t_transform	*custom;

	(void)gui;
	campaign = get_gui_child(game->ui, "missionscampaignbutton");
	custom = get_gui_child(game->ui, "missionscustombutton");
	switch_focus(custom, campaign);
	game->ui->mission_page = 0;
	set_page_number(game);
	remove_maps(game);
	load_missions(game);
}

void		mission_return(t_game *game, t_transform *gui)
{
	(void)gui;
	remove_mission(game);
	remove_maps(game);
}
