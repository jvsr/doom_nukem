/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_del.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:37:18 by ehollidg       #+#    #+#                */
/*   Updated: 2020/04/02 15:19:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"

#include "map_editor.h"

static void	free_wall(void *wall, size_t size)
{
	t_editor_wall *w;

	(void)size;
	w = wall;
	ft_memdel((void**)&w);
}

static void	free_obj(void *obj, size_t size)
{
	t_editor_object *o;

	(void)size;
	o = obj;
	ft_memdel((void**)&obj);
}

static void free_sector(void *sec, size_t size)
{
	t_editor_sector *sc;

	sc = sec;
	(void)size;
	ft_lstdel(&sc->objects, NULL);
	ft_lstdel(&sc->walls, NULL);
	ft_memdel((void**)&sec);
}

void		map_editor_del(t_editor_map **editor_map)
{
	if (editor_map == NULL || *editor_map == NULL)
		return ;
	ft_lstdel(&(*editor_map)->walls, free_wall);
	ft_lstdel(&(*editor_map)->objects, free_obj);
	ft_lstdel(&(*editor_map)->sectors, free_sector);
	ft_memdel((void**)editor_map);
}
