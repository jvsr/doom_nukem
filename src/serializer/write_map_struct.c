/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_map_struct.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 17:25:09 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 22:02:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"
#include "serializer.h"

void		write_map_struct(t_map *map, const char *loc, const char *exec_path)
{
	size_t i;
	t_binary	*bin;

	bin = new_binary();
	i = 0;
	// while (i < HEADER_AMT)
	// {
	// 	add_long(MAP_HEADER, bin);
	// 	i++;
	// }
	add_map(map, bin);
	finish_bin(bin);
	write_struct((char*)loc, bin, exec_path);
	del_binary(&bin);
}
