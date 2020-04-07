/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chair_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:08:26 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:48:52 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "types.h"
#include "rinfo.h"

t_anim		chair_init(t_object *obj, float offset)
{
	t_anim anim;

	anim.left[0] = TEXTURE_CHAIR_LEFT;
	anim.right[0] = TEXTURE_CHAIR_RIGHT;
	anim.front[0] = TEXTURE_CHAIR_FRONT;
	anim.back[0] = TEXTURE_CHAIR_BACK;
	anim.data = (void*)obj;
	anim.set_index = get_r_object_index;
	anim.offset = offset;
	return (anim);
}
