/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 13:05:10 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:54:30 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "enemy.h"
#include "error.h"

t_enemy		*read_enemy(t_object *obj, t_binary_read *bin_r)
{
	t_enemy *enemy;

	enemy = ft_memalloc(sizeof(t_enemy));
	if (enemy == NULL)
		error_msg_errno("Unable To Allocated Level Data");
	enemy->health = read_int(bin_r);
	enemy->last_seen = read_long(bin_r);
	enemy->state = read_int(bin_r);
	enemy->obj = obj;
	enemy->on_los = get_on_from_name(read_string(bin_r));
	enemy->no_los = get_no_from_name(read_string(bin_r));
	return (enemy);
}
