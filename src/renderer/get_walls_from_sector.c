/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_walls_from_sector.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 13:19:09 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/25 13:46:38 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "map.h"

t_wall		**get_walls_from_sector(t_sector *sector, t_level *level)
{
	return (level->walls + sector->startwall);
}
