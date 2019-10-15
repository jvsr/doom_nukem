/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:59:14 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/15 16:59:14 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

#include "map.h"
#include "coord.h"

typedef struct	s_hit
{
	t_vec		hit_pos;
}				t_hit;

void	render_3d(t_level *level);

#endif
