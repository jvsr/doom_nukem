/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:48:43 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 13:40:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "libft/ft_bool.h"
# include "rinfo.h"

typedef struct s_game	t_game;
typedef struct s_object	t_object;
typedef struct s_player	t_player;

void		enemy_move(t_game *game);
t_bool		check_enemy(t_game *game, t_object *obj);
void		shooty_func(t_game *game, t_object *obj, t_player *plr);
void		reset_func(t_game *game, t_object *obj);
char const	*get_no_name(t_nofunc *nofunc);
t_nofunc	*get_no_from_name(const char *name);
char const	*get_on_name(t_onfunc *onfunc);
t_onfunc	*get_on_from_name(const char *name);

#endif
