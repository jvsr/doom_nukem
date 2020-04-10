/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_anim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 15:47:36 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 13:37:35 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "serializer.h"
#include "textures.h"
#include "renderer.h"
#include "rinfo.h"

static t_anim	other_obj(t_objanim oa, t_object *obj, float off, t_texture s)
{
	t_anim anim;

	ft_bzero(&anim, sizeof(t_anim));
	if (oa == OA_CHAIR)
		return (chair_init(obj, off));
	else if (oa == OA_ENEMY)
		return (enemy_init(obj, s));
	return (anim);
}

t_anim			read_anim(t_binary_read *bin_r, t_object *obj)
{
	t_objanim	ao;
	float		offset;

	if (!read_char(bin_r))
		return (single_init(read_int(bin_r), obj));
	ao = read_int(bin_r);
	offset = read_float(bin_r);
	return (other_obj(ao, obj, offset, read_int(bin_r)));
}
