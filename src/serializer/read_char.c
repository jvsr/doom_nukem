/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:00:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/08 11:00:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

unsigned char	read_char(t_binary_read *bin_r)
{
	unsigned char c;

	c = *(bin_r->bytes + bin_r->content_pos);
	bin_r->content_pos += sizeof(char);
	return (c);
}
