/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:33:26 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/10 17:15:33 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "renderer.h"
#include "types.h"
#include "rinfo.h"

static void	left_add(t_anim *anim, t_texture start)
{
	int i;

	i = start;
	while (i - start < 4)
	{
		anim->left[i - start] = (t_texture)i;
		i++;
	}
}

static void	right_add(t_anim *anim, t_texture start)
{
	int i;

	i = start;
	while (i - start < 4)
	{
		anim->right[i - start] = (t_texture)i;
		i++;
	}
}

static void	back_add(t_anim *anim, t_texture start)
{
	int i;

	i = start;
	while (i - start < 4)
	{
		anim->back[i - start] = (t_texture)i;
		i++;
	}
}

static void	front_add(t_anim *anim, t_texture start)
{
	int i;

	i = start;
	while (i - start < 4)
	{
		anim->front[i - start] = (t_texture)i;
		i++;
	}
}

t_anim		enemy_init(t_object *obj, t_texture start)
{
	t_anim	anim;
	t_enemy	*enm;

	anim.set_index = get_enemy_index;
	anim.data = (void*)obj;
	enm = ft_memalloc(sizeof(t_enemy));
	enm->health = 20;
	enm->state = ENEMY_IDLE;
	obj->data = enm;
	front_add(&anim, start);
	back_add(&anim, start + 4);
	left_add(&anim, start + 8);
	right_add(&anim, start + 12);
	anim.actions[0] = start + 16;
	anim.actions[1] = start + 17;
	anim.actions[2] = start + 18;
	return (anim);
}
