/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_from_anim.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 14:26:13 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:49:02 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "types.h"
#include "rinfo.h"

SDL_Surface		*sdl_from_anim(t_game *game, t_anim *anim)
{
	anim->set_index(game, (void*)anim);
	if (anim->index.x == 0)
		return (get_texture(game, anim->left[anim->index.y]));
	else if (anim->index.x == 1)
		return (get_texture(game, anim->right[anim->index.y]));
	else if (anim->index.x == 2)
		return (get_texture(game, anim->front[anim->index.y]));
	else if (anim->index.x == 3)
		return (get_texture(game, anim->back[anim->index.y]));
	return (get_texture(game, anim->actions[anim->index.y]));
}
