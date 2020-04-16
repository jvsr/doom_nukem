/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_map_struct.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 17:25:09 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 15:22:03 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"
#include "serializer.h"

void		write_map_struct(t_map *map, const char *loc, const char *exec_path)
{
	t_binary	*bin;

	bin = new_binary();
	add_map(map, bin);
	finish_bin(bin);
	write_struct((char*)loc, bin, exec_path);
	del_binary(&bin);
}
