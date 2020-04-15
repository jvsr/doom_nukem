/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_get_sector.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/15 17:13:47 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 18:49:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"

static t_bool	check_cur(t_coord *pos, t_sector *cur)
{
	t_uint64	i;
	t_uint64	j;
	t_coord		vec;

	i = 0;
	j = 0;
	while (i < cur->wall_count)
	{
		if (get_collision(pos, &(t_coord){cos(90), sin(90)},
			(t_coord[2]){cur->walls[i].corner_0, cur->walls[i].corner_1}, &vec))
			j++;
		i++;
	}
	return ((t_bool)j % 2 == 1);
}

static t_list	*get_connected(t_sector *sec)
{
	t_uint64	i;
	t_wall		*wl;
	t_list		*lst;

	i = 0;
	lst = NULL;
	while (i < sec->wall_count)
	{
		wl = &sec->walls[i];
		if (wl->is_portal)
			ft_lstaddbck(&lst, ft_lstnew(wl->window, sizeof(t_sector)));
		i++;
	}
	return (lst);
}

static t_uint32	ret(t_list *lst, t_sector *sec, t_map *map)
{
	ft_lstdel(&lst, NULL);
	return (get_sector_id(map, sec));
}

static t_uint32	second_layer(t_list *lst, t_map *map, t_coord *pos)
{
	t_list	*secs;
	t_list	*s0;
	t_list	*s1;

	secs = lst;
	while (secs)
	{
		s0 = get_connected(secs->content);
		s1 = s0;
		while (s1)
		{
			if (check_cur(pos, s1->content))
			{
				ft_lstdel(&lst, NULL);
				return (ret(s0, s1->content, map));
			}
			s1 = s1->next;
		}
		ft_lstdel(&s0, NULL);
		secs = secs->next;
	}
	ft_lstdel(&secs, NULL);
	return (0);
}

t_uint32		player_get_sector(t_player *plyr, t_map *map, t_coord *pos)
{
	t_list	*secs;
	t_list	*tmp;

	if (check_cur(pos, &map->sectors[plyr->cur_sector]))
		return (plyr->cur_sector);
	secs = get_connected(&map->sectors[plyr->cur_sector]);
	tmp = secs;
	while (tmp)
	{
		if (check_cur(pos, tmp->content))
			return (ret(secs, tmp->content, map));
		tmp = tmp->next;
	}
	return (second_layer(secs, map, pos));
}
