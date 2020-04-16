/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_objs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:42:53 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:04:11 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_list.h"
#include "rinfo.h"

t_bool	sort_objs(const t_list *a, const t_list *b)
{
	return ((t_bool)(((t_objrend*)a->content)->dist <
			((t_objrend*)b->content)->dist));
}
