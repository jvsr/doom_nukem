/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:00:43 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 22:35:04 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "error.h"

unsigned char	read_char(t_binary_read *bin_r)
{
	unsigned char c;

	if (bin_r->content_pos - bin_r->header_size + sizeof(char) >
		bin_r->file_size)
		error_msg("No space in file", 876, "Serializer");
	c = *(bin_r->bytes + bin_r->content_pos);
	bin_r->content_pos += sizeof(char);
	return (c);
}
