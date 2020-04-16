/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_hinfo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:42:56 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 10:51:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "rinfo.h"
#include "error.h"

t_hinfo		*new_hinfo(t_sector *sec, size_t ar_size, size_t start)
{
	t_hinfo *info;

	info = ft_memalloc(sizeof(t_hinfo));
	if (info == NULL)
		error_msg_errno("Error allocating hinfo");
	info->sec = sec;
	info->hits = (t_hitem*)ft_memalloc(sizeof(t_hitem) * ar_size);
	if (info->hits == NULL)
		error_msg_errno("Error allocating hinfo hits");
	info->size = ar_size;
	info->start = start;
	return (info);
}
