/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:48:43 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/02 14:07:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

typedef struct s_game	t_game;
typedef struct s_object	t_object;
typedef struct s_player	t_player;

void	enemy_move(t_game *game);
t_bool	check_enemy(t_game *game, t_object *obj);
void	shooty_func(t_game *game, t_object *obj, t_player *plr);
void	reset_func(t_game *game, t_object *obj);

#endif
