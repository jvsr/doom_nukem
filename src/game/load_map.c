/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 09:47:55 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 21:34:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map_editor.h"
#include "textures.h"
#include "renderer.h"
#include "player.h"
#include "rinfo.h"
#include "game.h"

static t_bool	load_fc(t_object *obj, t_sector *sec, t_texture tex)
{
	if (tex == TEXTURE_CMINUS)
	{
		if (sec->floor < sec->ceil - 7.5)
			sec->ceil -= 2.5;
		del_obj(obj, sec);
		return (FALSE);
	}
	if (tex == TEXTURE_FPLUS)
	{
		if (sec->floor + 2.5 < sec->ceil - 5)
			sec->floor += 2.5;
		del_obj(obj, sec);
		return (FALSE);
	}
	if (tex == TEXTURE_FMINUS)
	{
		sec->floor -= 2.5;
		del_obj(obj, sec);
		return (FALSE);
	}
	return (TRUE);
}

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
	if (tex == TEXTURE_SLOPE)
	{
		sec->angle = 15;
		sec->has_slope = TRUE;
		sec->swall = &sec->walls[0];
		del_obj(obj, sec);
		return (FALSE);
	}
	if (tex == TEXTURE_CPLUS)
	{
		sec->ceil += 2.5;
		del_obj(obj, sec);
		return (FALSE);
	}
	return (load_fc(obj, sec, tex));
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
		obj->on_collide = end_col;
		return (TRUE);
	}
	return (load_skybox(game, obj, sec, tex));
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
	plyr->ammo = 15;
	plyr->keys = 0;
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
