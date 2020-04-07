/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/31 12:17:43 by euan          #+#    #+#                 */
/*   Updated: 2020/04/03 13:11:02 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "map_editor.h"
#include "coord.h"
#include "cmath.h"
#include "error.h"

static void		remove_sec(t_list *walls, t_editor_sector *sec)
{
	t_editor_wall *wall;

	while (walls)
	{
		wall = walls->content;
		if (wall->sectors[0] == sec)
			wall->sectors[0] = NULL;
		else
			wall->sectors[1] = NULL;
		walls = walls->next;
	}
}

static void		clean_up_dups(t_editor_map *map)
{
	t_list			*x;
	t_list			*y;
	t_editor_sector	*s0;
	t_editor_sector	*s1;

	x = map->sectors;
	while (x)
	{
		s0 = x->content;
		y = map->sectors;
		while (y)
		{
			s1 = y->content;
			if (s0 != s1 && ft_lstlen(s0->walls) == ft_lstlen(s1->walls) &&
				walls_equal(s0->walls, s1->walls))
			{
				remove_from_list(map->sectors, x);
				remove_sec(s1->walls, s1);
				ft_lstdel(&s1->walls, NULL);
				ft_memdel((void**)&s1);
			}
			y = y->next;
		}
		x = x->next;
	}
}

static void		make_sectors(t_list *cons, t_editor_map *map)
{
	while (cons)
	{
		ft_lstaddbck(&map->sectors,
			get_correct_sectors(cons->content, map->walls));
		cons = cons->next;
	}
	clean_up_walls(map);
	clean_up_dups(map);
	map_objects(map->sectors, map->objects);
}

static void		add_all_to_sector(t_list *walls, t_editor_map *map)
{
	t_editor_sector *sec;
	t_editor_wall	*tmp;
	t_editor_object	*obj;
	t_list			*lst;

	sec = ft_memalloc(sizeof(t_editor_sector));
	if (sec == NULL)
		error_msg_errno("Unable to allocate sector");
	sec->walls = walls;
	sec->objects = map->objects;
	lst = walls;
	while (lst)
	{
		tmp = lst->content;
		tmp->sectors[0] = sec;
		lst = lst->next;
	}
	lst = sec->objects;
	while (lst)
	{
		obj = lst->content;
		obj->sector = sec;
		lst = lst->next;
	}
	map->sectors = ft_lstnew(sec, sizeof(t_editor_sector));
}

t_bool			map_editor_clean(t_editor_map *map)
{
	t_list *cons;

	cons = get_connectors(map->walls);
	if (cons)
	{
		make_sectors(cons, map);
		ft_lstdel(&cons, NULL);
	}
	else
		add_all_to_sector(map->walls, map);
	return (TRUE);
}
