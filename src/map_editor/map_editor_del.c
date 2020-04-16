/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_del.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:37:18 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/08 15:55:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"

#include "map_editor.h"

void		free_ewall(void *wall, size_t size)
{
	t_editor_wall *w;

	(void)size;
	w = wall;
	ft_memdel((void**)&w);
}

void		free_eobj(void *obj, size_t size)
{
	(void)size;
	ft_memdel((void**)&obj);
}

void		free_esector(void *sec, size_t size)
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
	ft_lstdel(&(*editor_map)->walls, free_ewall);
	ft_lstdel(&(*editor_map)->objects, free_eobj);
	ft_lstdel(&(*editor_map)->sectors, free_esector);
	ft_memdel((void**)editor_map);
}
