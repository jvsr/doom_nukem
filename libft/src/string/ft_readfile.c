/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:30:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:31:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"
#include "ft_list.h"
#include <unistd.h>

static ssize_t	freeret(t_list *lst, char **str)
{
	*str = 0;
	ft_lstdel(&lst, &ft_lstdelmem);
	return (-1);
}

static char		*lsttostr(t_list *lst, size_t totallen)
{
	size_t	i;
	t_list	*next;
	char	*str;

	i = 0;
	if (lst == NULL)
		return (ft_strnew(0));
	str = ft_strnew(totallen);
	if (str == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->content != NULL)
			ft_memcpy(&str[i], lst->content, lst->content_size);
		i += lst->content_size;
		next = lst->next;
		ft_lstdelone(&lst, &ft_lstdelmem);
		lst = next;
	}
	return (str);
}

static t_bool	addtolst(t_list **lst, t_list **prv, char *str, size_t len)
{
	t_list	*new;

	new = ft_lstnew((void *)str, len);
	if (new == NULL)
		return (FALSE);
	if (*lst == NULL)
		*lst = new;
	else
		(*prv)->next = new;
	*prv = new;
	return (TRUE);
}

ssize_t			ft_readfile(int fd, char **str)
{
	t_list	*prv;
	t_list	*lst;
	ssize_t	ret;
	ssize_t	totallen;
	char	buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	lst = NULL;
	ret = read(fd, buff, BUFF_SIZE);
	totallen = 0;
	while (ret > 0)
	{
		totallen += ret;
		if (addtolst(&lst, &prv, buff, ret) == FALSE)
			return (freeret(lst, str));
		ret = read(fd, buff, BUFF_SIZE);
	}
	if (ret == -1)
		return (freeret(lst, str));
	*str = lsttostr(lst, totallen);
	if (*str == NULL)
		return (freeret(lst, str));
	return (totallen);
}
