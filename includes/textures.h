/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:10:27 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/11 13:08:41 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "rinfo.h"

t_anim			lamp_init(void);
t_anim			chair_init(t_object *obj, float offset);
t_anim			single_init(t_texture texture, void *data);
t_anim			enemy_init(t_object *obj, t_texture start);

#endif
