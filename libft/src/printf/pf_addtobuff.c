/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addtobuff.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 22:58:40 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 15:58:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"
#include <unistd.h>

static t_bool	addtolst(t_info *info)
{
	static	t_list	*prv;
	t_list			*new;

	new = ft_lstnew_dup(info->buff, PF_BUFF_SIZE);
	if (prv == NULL)
		info->buff_list = new;
	else
		ft_lstaddbck(&prv, new);
	prv = new;
	return (prv != NULL);
}

t_bool			pf_addtobuff(t_info *info, const char *str, size_t len)
{
	t_bool	ret;
	size_t	fit;

	if ((len + info->buff_len) > PF_BUFF_SIZE)
	{
		fit = PF_BUFF_SIZE - info->buff_len;
		ft_memcpy(&info->buff[info->buff_len], str, fit);
		if (info->fd == -1)
			ret = addtolst(info);
		else
			ret = (write(info->fd, info->buff, PF_BUFF_SIZE) != -1);
		info->added += fit;
		info->buff_len = 0;
		ft_bzero(info->buff, PF_BUFF_SIZE);
		if (ret == FALSE)
			return (FALSE);
		return (pf_addtobuff(info, &str[fit], len - fit));
	}
	ft_memcpy(&info->buff[info->buff_len], str, len);
	info->buff_len += len;
	info->added += len;
	return (TRUE);
}
