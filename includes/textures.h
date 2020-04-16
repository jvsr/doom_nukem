/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:10:27 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/03/30 11:07:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "rinfo.h"
# include "types.h"

SDL_Surface		*get_texture(t_game *game, t_texture texture);
void			load_textures(t_game *game);
SDL_Surface		*sdl_from_anim(t_game *game, t_anim *anim);
t_anim			chair_init(t_object *obj, float offset);
t_anim			single_init(t_texture texture, void *data);
t_anim			enemy_init(t_object *obj, t_texture start);
void			get_s_object_index(t_game *game, void *anim);
void			get_r_object_index(t_game *game, void *anim);
void			get_enemy_index(t_game *game, void *anim);
float			get_object_angle_on_screen(t_object *object,
					t_player *player, t_coord *range);
t_texture		get_tex_for_obj(t_obj obj);
t_texture		tex_from_anim(t_game *game, t_anim *anim);

#endif
