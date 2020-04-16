/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mission1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 12:35:07 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:36:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/ft_num.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"

static void	switch_focus(t_transform *focus, t_transform *no_focus)
{
	set_elem_layer(focus, 4);
	set_elem_layer(no_focus, 3);
	set_elem_text_color(focus, (SDL_Color){227, 227, 227, 255});
	set_elem_text_color(no_focus, (SDL_Color){102, 102, 102, 255});
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
	campaign = get_gui_child(game->ui, "missionsCampaignButton");
	custom = get_gui_child(game->ui, "missionsCustomButton");
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
	campaign = get_gui_child(game->ui, "missionsCampaignButton");
	custom = get_gui_child(game->ui, "missionsCustomButton");
	switch_focus(custom, campaign);
	game->ui->mission_page = 0;
	set_page_number(game);
	remove_maps(game);
	load_missions(game);
}
