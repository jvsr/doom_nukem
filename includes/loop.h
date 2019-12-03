/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:36:03 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 16:36:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

#include "eventstate.h"

void		loop_core(t_game *game, t_eventstate_code code);
void		loop_game(t_game *game);

#endif