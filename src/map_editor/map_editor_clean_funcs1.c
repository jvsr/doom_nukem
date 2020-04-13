/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean_funcs1.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:41:08 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 14:36:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "map_editor.h"
#include "coord.h"
#include "error.h"
#include "cmath.h"

t_coord			get_wall_vector(t_editor_wall *main, t_editor_wall *sec)
{
	const size_t	csize = sizeof(t_coord);
	t_coord			vec;

	if (ft_memequ(&main->corner_0, &sec->corner_0, csize)
	|| ft_memequ(&main->corner_0, &sec->corner_1, csize))
		get_vector_from_points(&main->corner_1, &main->corner_0, &vec);
	else
		get_vector_from_points(&main->corner_0, &main->corner_1, &vec);
	normalize_vector(&vec);
	return (vec);
}

void			remove_from_list(t_list **head, t_list *elm)
{
	t_list *i;
	t_list *prv;

	i = *head;
	prv = NULL;
	while (i != elm)
	{
		prv = i;
		i = i->next;
	}
	if (prv != NULL && i != NULL)
		prv->next = i->next;
	else if (i != NULL)
		*head = i->next;
	if (i != NULL)
		i->next = NULL;
}

void			clean_up_walls(t_editor_map *map)
{
	t_list			*lst;
	t_editor_sector	*sec;
	t_editor_wall	*wall;

	sec = NULL;
	lst = map->walls;
	while (lst)
	{
		wall = lst->content;
		if (wall->sectors[0] == NULL && wall->sectors[1] == NULL)
		{
			if (sec == NULL)
			{
				sec = ft_memalloc(sizeof(t_editor_sector));
				if (sec == NULL)
					error_msg_errno("Unable to allocate sector");
				sec->is_invalid = TRUE;
			}
			ft_lstaddbck(&sec->walls, ft_lstnew(wall, sizeof(t_editor_wall)));
		}
		lst = lst->next;
	}
	if (sec != NULL)
		ft_lstaddbck(&map->sectors, ft_lstnew(sec, sizeof(t_editor_sector)));
}

static t_bool	sort_memoryard(t_list const *lst1, t_list const *lst2)
{
	return ((size_t)lst1->content > (size_t)lst2->content);
}

t_bool			walls_equal(t_list **w0, t_list **w1)
{
	t_list	*lst1;
	t_list	*lst2;

	ft_lstsort(w0, sort_memoryard);
	ft_lstsort(w1, sort_memoryard);
	lst1 = *w0;
	lst2 = *w1;
	while (lst1 && lst2 && lst1->content == lst2->content)
	{
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (lst1 == NULL && lst2 == NULL);
}
