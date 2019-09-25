/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 12:37:02 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 15:51:24 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef enum	e_state
{
	IDLE_state,
	DASH_state,
	SPACE_state,
	ID_state,
	COLON_state,
	NUM_state,
	NEWLINE_state,
	COLON_SPACE_state,
	MAX_STATES,
}				t_state;

typedef enum	e_event
{
	idle_handler,
	dash_handler,
	space_handler,
	id_handler,
	colon_handler,
	num_handler,
	newline_handler,
	colon_space_handler,
	wildcard_handler,
	MAX_EVENTS,
}				t_event;

// t_state	(*state_table[MAX_STATES][MAX_EVENTS]) = {
// 	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
// 	{dash_space_event_handler, id_event_handler},
// 	{id_event_handler, colon_event_handler},
// 	{colon_event_handler, colon_space_event_handler, EMPTY, newline_handler, colon_wildcard_handler, NULL},
// 	{space_event_handler, colon_space_event_handler, EMPTY, newline_handler, colon_wildcard_handler},
// 	{NULL,},
// 	{},
// 	{},
// };

#endif
