/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformgetbyname.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:27:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 11:36:15 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

static t_transform	*checkchildren(t_transform *trans, char *name)
{
	t_list		*lst;
	t_transform	*ret;

	if (ft_strequ(name, trans->name))
		return (trans);
	lst = trans->children;
	while (lst != NULL)
	{
		ret = checkchildren(lst->content, name);
		if (ret != NULL)
			return (ret);
	}
	return (NULL);
}

t_transform		*transformgetbyname(t_gui *ui, char *name)
{
	return (checkchildren(&ui->transform, name));
}
