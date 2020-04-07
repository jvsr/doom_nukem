/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_coord.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 16:24:03 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:58:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "coord.h"

t_coord			read_coord(t_binary_read *bin_r)
{
	return ((t_coord){read_double(bin_r), read_double(bin_r)});
}
