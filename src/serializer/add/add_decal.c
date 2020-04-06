/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_decal.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:05:58 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:56:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "rinfo.h"

void		add_decal(t_decal *decal, t_binary *bin)
{
	add_coord(&decal->pos, bin);
	add_coord(&decal->size, bin);
	add_anim(&decal->texture, bin);
}
