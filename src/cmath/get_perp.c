/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_perp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 14:05:12 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:05 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"

t_coord		get_perp(t_coord *vec)
{
	return ((t_coord){vec->y, vec->x});
}
