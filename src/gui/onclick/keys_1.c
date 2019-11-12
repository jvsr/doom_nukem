/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys_1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 22:12:19 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 15:51:03 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "gui.h"
#include "game.h"
#include "setting.h"
#include "eventstate.h"

void	controls_set_forward(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.forward;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}

void	controls_set_backward(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.backward;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}

void	controls_set_left(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.left;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}

void	controls_set_right(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.right;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}

void	controls_set_interact(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.interact;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}
