/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:07:06 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:48:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "types.h"
#include "rinfo.h"

t_anim		single_init(t_texture texture, void *data)
{
	t_anim	anim;

	anim.left[0] = texture;
	anim.right[0] = TEXTURE_INVALID;
	anim.back[0] = TEXTURE_INVALID;
	anim.front[0] = TEXTURE_INVALID;
	anim.set_index = get_s_object_index;
	anim.data = data;
	return (anim);
}
