/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_delete.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:37:18 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/14 21:41:32 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "rinfo.h"

void	free_wall(t_wall *wall)
{
	if (wall == NULL)
		return ;
	if (wall->decals)
		ft_lstdel(&wall->decals, ft_lstdelmem);
}

void	free_obj(void *obj, size_t size)
{
	t_object *o;

	if (obj == NULL)
		return ;
	(void)size;
	o = obj;
	if (o->data != NULL)
		ft_memdel(&o->data);
	ft_memdel(&obj);
}

void	free_sector(t_sector *sector)
{
	size_t		i;

	if (sector == NULL)
		return ;
	if (sector->objects)
		ft_lstdel(&sector->objects, free_obj);
	i = 0;
	while (i < sector->wall_count)
	{
		free_wall(sector->walls + i);
		i++;
	}
	ft_memdel((void**)&sector->walls);
}

void	delete_map(t_map **map)
{
	size_t	i;

	i = 0;
	if (map == NULL || *map == NULL)
		return ;
	while (i < (*map)->sector_count)
	{
		free_sector((*map)->sectors + i);
		i++;
	}
	ft_memdel((void**)&(*map)->sectors);
	ft_memdel((void**)map);
}
