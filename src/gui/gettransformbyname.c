/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gettransformbyname.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:27:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:24:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

t_transform			*gettransformbyname(t_gui *ui, char *name)
{
	return (gettransforminchildren(&ui->transform, name));
}
