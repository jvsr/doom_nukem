/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:10:27 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/06 12:10:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "rinfo.h"

t_anim			lamp_init(void);
t_anim			chair_init(t_object *obj, float offset);
t_anim			single_init(t_texture texture);

#endif
