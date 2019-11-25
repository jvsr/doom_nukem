/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:05:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 15:05:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "serializer.h"

void		add_string(char *string, t_binary *bin)
{
	add_mem(string, ft_strlen(string) + 1, bin);
}
