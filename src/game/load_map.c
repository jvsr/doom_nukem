/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 09:47:55 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 20:35:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map_editor.h"
#include "textures.h"
#include "renderer.h"
#include "player.h"
#include "rinfo.h"
#include "game.h"

static t_bool	load_skybox(t_game *game, t_object *obj,
					t_sector *sec, t_texture tex)
{
	if (tex == TEXTURE_SKYBOX_DAY || tex == TEXTURE_SKYBOX_DUSK)
	{
		sec->has_ceiling = FALSE;
		game->map->has_skybox = TRUE;
		game->map->skybox = tex;
		del_obj(obj, sec);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	start_end(t_game *game,
					t_object *obj, t_player *plyr, t_sector *sec)
{
	t_texture	tex;

	if (obj == NULL)
		return (TRUE);
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
	return (load_skybox(game, obj, sec, tex));
}

static void		shrinkwall(t_wall *wall)
{
	wall->corner_0 = (t_coord){wall->corner_0.x / SHRINK_SIZE,
		wall->corner_0.y / SHRINK_SIZE};
	wall->corner_1 = (t_coord){wall->corner_1.x / SHRINK_SIZE,
		wall->corner_1.y / SHRINK_SIZE};
}

static void		shrink(t_map *map)
{
	t_uint64	i;
	t_list		*lst;
	t_object	*obj;
	t_uint64	j;

	i = 0;
	while (i < map->sector_count)
	{
		lst = map->sectors[i].objects;
		while (lst)
		{
			obj = lst->content;
			obj->pos = (t_coord){obj->pos.x / SHRINK_SIZE,
				obj->pos.y / SHRINK_SIZE};
			lst = lst->next;
		}
		j = 0;
		while (j < map->sectors[i].wall_count)
		{
			shrinkwall(&map->sectors[i].walls[j]);
			j++;
		}
		i++;
	}
}

void			load_map(t_game *game, t_map *map, t_player *plyr)
{
	t_uint64	i;
	t_uint64	j;
	t_list		*lst;
	t_sector	*sec;

	delete_map(&game->map);
	game->map = map;
	shrink(map);
	i = 0;
	plyr->health = PLAYER_MAX_HEALTH;
	plyr->is_dead = FALSE;
	while (i < map->sector_count)
	{
		j = 0;
		sec = map->sectors + i;
		while (j < sec->object_count)
		{
			lst = ft_lstindex(sec->objects, j);
			if (start_end(game, lst->content, plyr, sec))
				j++;
		}
		i++;
	}
}
