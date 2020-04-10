/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean_funcs1.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:41:08 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 13:03:17 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "map_editor.h"
#include "coord.h"
#include "error.h"
#include "cmath.h"

t_coord		get_wall_vector(t_editor_wall *main, t_editor_wall *sec)
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

void		remove_from_list(t_list **head, t_list *elm)
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

t_list		*get_correct_sectors(t_editor_wall *con, t_list *walls)
{
	t_list 	*secs;

	secs = NULL;
	if (con->sectors[0] == NULL && con->sectors[1] == NULL)
	{
		ft_lstaddbck(&secs,
			ft_lstnew(get_room(ft_lstnew(con,
				sizeof(t_editor_wall)), walls, con, FALSE), sizeof(t_list)));
		ft_lstaddbck(&secs,
			ft_lstnew(get_room(ft_lstnew(con,
				sizeof(t_editor_wall)), walls, con, TRUE), sizeof(t_list)));
	}
	else if (con->sectors[0] != NULL && con->sectors[1] != NULL)
		return (NULL);
	else
	{
		t_editor_sector *sec;
		t_list			*cons;
		t_coord			vec;
		t_coord			tvec;

		if (con->sectors[0])
			sec = con->sectors[0];
		else
			sec = con->sectors[1];
		cons = get_walls_at_point(&con->corner_0, sec->walls, con);
		vec = get_wall_vector(con, cons->content);
		tvec = get_wall_vector(cons->content, con);
		if (get_side_vec(&vec, &tvec, TRUE) == 1)
			ft_lstaddbck(&secs, ft_lstnew(get_room(ft_lstnew(con,
				sizeof(t_editor_wall)), walls, con, FALSE), sizeof(t_list)));
		else
			ft_lstaddbck(&secs,	ft_lstnew(get_room(ft_lstnew(con,
				sizeof(t_editor_wall)), walls, con, TRUE), sizeof(t_list)));
	}
	return (secs);
}

void		clean_up_walls(t_editor_map *map)
{
	t_list			*lst;
	t_editor_sector	*sec;
	t_editor_wall	*wall;

	sec = NULL;
	lst = map->walls;
	while (lst)
	{
		wall = lst->content;
		if (wall->sectors[0] == NULL)
		{
			if (sec == NULL)
			{
				sec = ft_memalloc(sizeof(t_editor_sector));
				if (sec == NULL)
					error_msg_errno("Unable to allocate sector");
			}
			ft_lstaddbck(&sec->walls, ft_lstnew(wall, sizeof(t_editor_wall)));
		}
		lst = lst->next;
	}
	if (sec != NULL)
		ft_lstaddbck(&map->sectors, ft_lstnew(sec, sizeof(t_editor_sector)));
}

t_bool		walls_equal(t_list *w0, t_list *w1)
{
	while (w0 && w1 && w0->content == w1->content)
	{
		w0 = w0->next;
		w1 = w1->next;
	}
	return (w0 == NULL && w1 == NULL);
}
