/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:10:27 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/27 15:02:41 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "rinfo.h"

SDL_Surface		*get_texture(t_game *game, t_texture texture);
void			load_textures(t_game *game);
SDL_Surface		*tex_from_anim(t_game *game, t_anim *anim);
t_anim			chair_init(t_object *obj, float offset);
t_anim			single_init(t_texture texture, void *data);
t_anim			enemy_init(t_object *obj, t_texture start);

#endif
