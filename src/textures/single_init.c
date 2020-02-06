/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:07:06 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/06 12:07:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "rinfo.h"
#include "renderer.h"

t_anim		single_init(t_texture texture)
{
	t_anim	anim;

	anim.left[0] = texture;
	anim.set_index = get_s_object_index;
	return (anim);
}
