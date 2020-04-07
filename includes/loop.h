/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:36:03 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/02/14 15:10:44 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "eventstate.h"

void		loop_core(t_game *game, t_eventstate_code code);
void		loop_game(t_game *game);
void		loop_map_editor(t_game *game);
void		loop_game_gui(t_game *game);

#endif
