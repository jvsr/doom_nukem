/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_table.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:30:17 by ehollidg      #+#    #+#                 */
/*   Updated: 2019/12/03 16:30:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_TABLE_H
# define LOOP_TABLE_H

# include "eventstate.h"
# include "loop.h"

typedef void	(t_loop_func)(t_game *);

typedef struct	s_loop_elm
{
	int			val;
	t_loop_func	*func;
}				t_loop_elm;

static t_loop_elm const g_loop_table[] =
{
	{hud, loop_game},
	{map_editor, loop_map_editor},
	{0, NULL}
};

#endif
