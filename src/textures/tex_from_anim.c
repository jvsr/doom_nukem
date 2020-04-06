/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex_from_anim.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 11:05:07 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:48:55 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "types.h"
#include "rinfo.h"

t_texture		tex_from_anim(t_game *game, t_anim *anim)
{
	anim->set_index(game, (void*)anim);
	if (anim->index.x == 0)
		return (anim->left[anim->index.y]);
	else if (anim->index.x == 1)
		return (anim->right[anim->index.y]);
	else if (anim->index.x == 2)
		return (anim->front[anim->index.y]);
	else if (anim->index.x == 3)
		return (anim->back[anim->index.y]);
	return (anim->actions[anim->index.y]);
}
