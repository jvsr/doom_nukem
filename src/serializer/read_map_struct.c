/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_struct.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 17:32:17 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 18:38:02 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "rinfo.h"
#include "error.h"

static void	check_header(t_binary_read *bin)
{
	long	boobie;
	size_t	i;

	i = 0;
	while (i < HEADER_AMT)
	{
		boobie = read_long(bin);
		if (boobie != MAP_HEADER)
			error_msg("Invalid map header", 234, "Map error");
		i++;
	}
}

t_map		*read_map_struct(char const *loc, char const *exec_path)
{
	t_map			*map;
	t_binary_read	*bin;

	bin = new_binary_read(loc, TRUE, exec_path);
	check_header(bin);
	map = read_map(bin);
	del_binary_read(&bin);
	return (map);
}
