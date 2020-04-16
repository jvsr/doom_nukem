/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_decal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:11:04 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:54:35 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

t_decal		read_decal(t_binary_read *bin_r)
{
	t_decal decal;

	decal.pos = read_coord(bin_r);
	decal.size = read_coord(bin_r);
	decal.texture = read_anim(bin_r, NULL);
	return (decal);
}
