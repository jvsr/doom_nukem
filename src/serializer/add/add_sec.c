/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_sec.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 15:11:11 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "serializer.h"

static void	add_walls(t_sector *sec, t_binary *bin, t_map *map)
{
	t_uint64 i;

	i = 0;
	while (i < sec->wall_count)
	{
		add_wall(&sec->walls[i], bin, map);
		i++;
	}
}

static void	add_objs(t_sector *sec, t_binary *bin)
{
	t_uint64	i;
	t_list		*lst;

	i = 0;
	lst = sec->objects;
	while (i < sec->object_count && lst != NULL)
	{
		add_obj(lst->content, bin);
		lst = lst->next;
		i++;
	}
}

static int	get_swall(t_sector *sec)
{
	t_uint64 i;

	if (!sec->has_slope || sec->swall == NULL)
		return (-1);
	i = 0;
	while (i < sec->wall_count)
	{
		if (sec->swall == sec->walls + 1)
			return (i);
		i++;
	}
	return (-1);
}

void		add_sec(t_sector *sec, t_binary *bin, t_map *map)
{
	add_long(sec->wall_count, bin);
	add_long(sec->object_count, bin);
	add_walls(sec, bin, map);
	add_objs(sec, bin);
	add_float(sec->floor, bin);
	add_float(sec->ceil, bin);
	add_int(sec->floor_tex, bin);
	add_int(sec->ceil_tex, bin);
	add_char((char)sec->has_ceiling, bin);
	add_float(sec->light_value, bin);
	add_char((char)sec->has_slope, bin);
	add_float(sec->angle, bin);
	add_int(get_swall(sec), bin);
}
