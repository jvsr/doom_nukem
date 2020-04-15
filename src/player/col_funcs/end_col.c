/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_col.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 19:21:31 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 19:25:10 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "player.h"
#include "types.h"
#include "rinfo.h"
#include "game.h"

void		end_col(t_game *game,
							t_sector *sec, t_object *obj, t_player *player)
{
	(void)obj;
	(void)player;
	win_enter(game, sec);
}
