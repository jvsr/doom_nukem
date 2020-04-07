/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_s_object_index.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 14:30:37 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:49:27 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"
#include "types.h"

void		get_s_object_index(t_game *game, void *anim)
{
	((t_anim*)anim)->index = (SDL_Point){0, 0};
	(void)game;
}
