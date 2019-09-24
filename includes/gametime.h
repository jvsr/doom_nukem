/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gametime.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 13:15:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/24 13:15:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMETIME_H
# define GAMETIME_H

# include <time.h>
# define CLOCKS_PER_MILLI (CLOCKS_PER_SEC / 1000)

typedef struct	s_time
{
	clock_t		start;
}				t_time;

void		init_gametime(t_time *time);
long		get_gametime(t_time *time);

#endif
