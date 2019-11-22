/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate_transition_table.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:05:18 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/14 11:46:03 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTSTATE_TRANSITION_TABLE_H
# define EVENTSTATE_TRANSITION_TABLE_H

# include "eventstate.h"

typedef void		(t_eventstate_fnc)(t_game *, SDL_Event);

static t_eventstate_fnc	*const g_eventstate[] =
{
	mainmenu_eventstate,
	missions_eventstate,
	options_eventstate,
	options_confirmation_eventstate,
	controls_eventstate,
	set_controls_eventstate,
	map_editor_eventstate,
	map_editor_select_eventstate,
};

#endif
