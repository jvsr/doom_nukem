/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_binary_read.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:26:16 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:51:58 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

void		del_binary_read(t_binary_read **bin_r)
{
	ft_memdel((void**)&(*bin_r)->bytes);
	ft_memdel((void**)bin_r);
}
