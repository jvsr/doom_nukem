/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformgetinchildren.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:46:42 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 11:48:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

t_transform	*transformgetinchildren(t_transform *trans, char *name)
{
	t_list		*lst;
	t_transform	*ret;

	if (trans == NULL)
		return (NULL);
	lst = trans->children;
	while (lst != NULL)
	{
		ret = checkchildren(lst->content, name);
		if (ret != NULL)
			return (ret);
	}
	return (NULL);
}
