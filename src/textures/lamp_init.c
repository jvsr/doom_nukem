/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lamp_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 14:41:58 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/05 14:41:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "rinfo.h"
#include "renderer.h"

t_anim		lamp_init(void)
{
	t_anim anim;

	anim.left[0] = TEXTURE_LAMP;
	anim.set_index = get_s_object_index;
	return (anim);
}
