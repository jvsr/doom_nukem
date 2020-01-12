/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 22:12:37 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 15:50:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_mem.h"

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "setting.h"
#include "eventstate.h"

void	set_key_str(SDL_Keycode keycode, t_transform *self)
{
	const char	*keystate = get_keystate_name(keycode);

	set_elem_text_str(self, keystate);
}

void	controls_set_shoot(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.shoot;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}

void	controls_set_crouch(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.crouch;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}

void	controls_set_jump(t_game *game, t_transform *gui)
{
	t_transform	*elem;
	t_types		*arguments;

	elem = get_gui_child(game->ui, "controlskeychange");
	set_elem_show_clickable(elem, TRUE);
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 3);
	arguments[0] = (t_types)&game->setting->controls.jump;
	arguments[1] = (t_types)(void*)elem;
	arguments[2] = (t_types)(void*)gui;
	game->cureventstate->arguments = arguments;
}
