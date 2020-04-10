/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 09:47:55 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 13:43:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "textures.h"
#include "renderer.h"
#include "player.h"
#include "rinfo.h"
#include "game.h"

static int	get_sec_num(t_map *map, t_sector *sec)
{
	t_uint64 i;

	i = 0;
	while (i < map->sector_count)
	{
		if (sec == map->sectors + i)
			return (i);
		i++;
	}
	return (i - 1);
}

static t_bool	start_end(t_game *game,
								t_object *obj, t_player *plyr, t_sector *sec)
{
	t_texture tex;

	tex = tex_from_anim(game, &obj->img);
	if (tex == TEXTURE_START)
	{
		plyr->pos = obj->pos;
		plyr->cur_sector = get_sec_num(game->map, sec);
		del_obj(obj, sec);
		return (FALSE);
	}
	if (tex == TEXTURE_END)
	{
		sec->f_enter = win_enter;
		del_obj(obj, sec);
		return (FALSE);
	}
	return (TRUE);
}

void		load_map(t_game *game, t_map *map, t_player *plyr)
{
	t_uint64	i;
	t_uint64	j;
	t_sector	*sec;

	delete_map(&game->map);
	game->map = map;
	i = 0;
	while (i < map->sector_count)
	{
		j = 0;
		sec = map->sectors + i;
		while (j < sec->object_count)
		{
			if (start_end(game,
				ft_lstindex(sec->objects, j)->content, plyr, sec))
				j++;
		}
		i++;
	}
}
