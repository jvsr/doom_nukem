/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_s_object_index.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 14:30:37 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/04 12:16:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"
#include "types.h"

void		get_s_object_index(t_game *game, void *anim)
{
	((t_anim*)anim)->index = (SDL_Point){0, 0};
	(void)game;
}
