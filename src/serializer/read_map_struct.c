/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_struct.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 17:32:17 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 15:22:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "rinfo.h"
#include "error.h"

t_map		*read_map_struct(char const *loc, char const *exec_path)
{
	t_map			*map;
	t_binary_read	*bin;

	bin = new_binary_read(loc, TRUE, exec_path);
	map = read_map(bin);
	del_binary_read(&bin);
	return (map);
}
