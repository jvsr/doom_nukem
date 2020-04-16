/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_rendobj.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:35:56 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:03:20 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "rinfo.h"
#include "error.h"

t_objrend	*new_rendobj(t_object *obj, t_sector *sec, float *flts, int x)
{
	t_objrend *robj;

	robj = ft_memalloc(sizeof(t_objrend));
	if (robj == NULL)
		error_msg_errno("Failed to alloc Render Object");
	*robj = (t_objrend){flts[0], obj, sec, flts[1], x};
	return (robj);
}
