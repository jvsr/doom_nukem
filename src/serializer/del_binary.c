/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_binary.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:06:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 16:06:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

void	del_binary(t_binary **bin)
{
	ft_memdel((void**)&(*bin)->content);
	ft_memdel((void**)&(*bin)->header);
	ft_memdel((void**)bin);
	*bin = NULL;
}
