/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_core.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:29:01 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 16:29:01 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "loop_table.h"

void		loop_core(t_game *game, t_eventstate_code code)
{
	int i;

	i = 0;
	while (g_loop_table[i].func != NULL)
	{
		if (g_loop_table[i].val == (const int)code)
			return g_loop_table[i].func(game);
		i++;
	}
	return ;
}
