/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformgetinchildren.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:46:42 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:15:47 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

t_transform	*gettransforminchildren(t_transform *trans, char *name)
{
	t_list		*lst;
	t_transform	*ret;

	if (trans == NULL)
		return (NULL);
	if (ft_strequ(trans->name, name))
		return (trans);
	lst = trans->children;
	while (lst != NULL)
	{
		ret = gettransforminchildren(lst->content, name);
		if (ret != NULL)
			return (ret);
	}
	return (NULL);
}
