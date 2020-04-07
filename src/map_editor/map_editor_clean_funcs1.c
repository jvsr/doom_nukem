/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean_funcs1.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:41:08 by euan          #+#    #+#                 */
/*   Updated: 2020/04/07 13:39:00 by jvisser       ########   odam.nl         */
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

	printf("%p\n%p %f,%f,\n%p %f,%f,\n\n%p\n%p %f,%f,\n%p %f,%f\n\n",
										main,
										&main->corner_0, main->corner_0.x, main->corner_0.y,
										&main->corner_1, main->corner_1.x, main->corner_1.y,
										sec,
										&sec->corner_0, sec->corner_0.x, sec->corner_0.y,
										&sec->corner_1, sec->corner_1.x, sec->corner_1.y);
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
	t_list *secs;

	secs = NULL;
	printf("Left\n\n");
	ft_lstaddbck(&secs,
		ft_lstnew(lft_room(ft_lstnew(con, sizeof(t_editor_wall)), walls, con), sizeof(t_list)));
	printf("Right\n\n");
	ft_lstaddbck(&secs,
		ft_lstnew(right_room(ft_lstnew(con, sizeof(t_editor_wall)), walls, con), sizeof(t_list)));
	printf("Sectors : %zu\n", ft_lstlen(secs));
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
