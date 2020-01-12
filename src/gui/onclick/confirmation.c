/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   confirmation.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:19:01 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 15:39:07 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "onclick.h"
#include "eventstate.h"

void	add_confirmation(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "confirmationmenu");
	overlay = get_gui_child(game->ui, "confirmationoverlay");
	set_elem_show_clickable(menu, TRUE);
	set_elem_show_clickable(overlay, TRUE);
}

void	remove_confirmation(t_game *game)
{
	t_transform	*menu;
	t_transform	*overlay;

	menu = get_gui_child(game->ui, "confirmationmenu");
	overlay = get_gui_child(game->ui, "confirmationoverlay");
	set_elem_show_clickable(menu, FALSE);
	set_elem_show_clickable(overlay, FALSE);
}

void	confirmation_return(t_game *game, t_transform *gui)
{
	(void)gui;
	remove_confirmation(game);
	remove_options(game);
	game->cureventstate->eventstate = mainmenu;
}

void	restart_game(t_game *game, t_transform *gui)
{
	char		full_path[PATH_MAX];

	(void)gui;
	ft_strcpy(full_path, game->exec_path);
	ft_strcat(full_path, game->exec_name);
	execve(full_path, game->argv, game->envp);
	quit(0);
}
