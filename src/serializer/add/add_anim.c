/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_anim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 15:18:12 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:00:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "textures.h"
#include "renderer.h"
#include "rinfo.h"

static int		get_object(t_anim *anim)
{
	if (anim->left[0] == TEXTURE_CHAIR_LEFT)
		return (OA_CHAIR);
	else if (anim->left[0] == TEXTURE_ENEMY0_L0)
		return (OA_ENEMY);
	return (OA_INVALID);
}

static t_bool	is_tex_or_anim(t_anim *anim)
{
	if (*anim->left != TEXTURE_INVALID && *anim->right == TEXTURE_INVALID &&
		*anim->front == TEXTURE_INVALID && *anim->back == TEXTURE_INVALID)
		return (1);
	return (0);
}

void			add_anim(t_anim *anim, t_binary *bin)
{
	if (is_tex_or_anim(anim))
	{
		add_char(0, bin);
		add_int(anim->left[0], bin);
		return ;
	}
	add_char(1, bin);
	add_int(get_object(anim), bin);
	add_float(anim->offset, bin);
	add_int(anim->front[0], bin);
}
