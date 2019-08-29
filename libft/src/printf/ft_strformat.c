/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strformat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:23 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:25:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_memory.h"

static char		*joinlst(t_info *info)
{
	size_t	i;
	char	*str;
	t_list	*lst;

	i = 0;
	lst = info->buff_list;
	str = ft_strnew(info->added);
	if (str == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_memcpy(&str[i], lst->content, lst->content_size);
		i += lst->content_size;
		lst = lst->next;
	}
	if (info->buff_len != 0)
		ft_memcpy(&str[i], info->buff, info->buff_len);
	return (str);
}

static char		*freeret(t_info *info)
{
	char	*str;

	if (info->buff_len == info->added)
	{
		str = ft_strnew(info->added);
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, info->buff, info->added);
	}
	else
		str = joinlst(info);
	ft_lstdel(&info->buff_list, &ft_lstdelmem);
	if (info != NULL)
	{
		ft_strdel(&info->buff);
		free(info);
	}
	return (str);
}

char			*ft_strformat(const char *format, ...)
{
	size_t	i;
	t_info	*info;

	i = 0;
	info = pf_infonew();
	if (info == NULL)
		return (NULL);
	info->fd = -1;
	va_start(info->args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i += pf_distribute(info, &format[i + 1]);
		else
			i += pf_addstr(info, &format[i]);
		i++;
	}
	va_end(info->args);
	return (freeret(info));
}
