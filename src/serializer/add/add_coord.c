/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_coord.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 16:19:22 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:01:02 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "coord.h"

void		add_coord(t_coord *coord, t_binary *bin)
{
	add_double(coord->x, bin);
	add_double(coord->y, bin);
}
