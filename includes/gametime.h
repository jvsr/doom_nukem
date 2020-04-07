/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gametime.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 13:15:43 by ehollidg      #+#    #+#                 */
/*   Updated: 2019/09/24 13:15:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMETIME_H
# define GAMETIME_H

# include <sys/time.h>
# include "types.h"

typedef struct timeval	t_time;

void		init_gametime(t_time *time);
t_uint64	get_gametime(t_time *time);

#endif
