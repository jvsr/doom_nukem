/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformgetbyname.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:27:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 13:29:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

t_transform			*transformgetbyname(t_gui *ui, char *name)
{
	return (transformgetinchildren(&ui->transform, name));
}
