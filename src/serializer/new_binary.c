/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_binary.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:01:47 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 16:01:47 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

t_binary	*new_binary(void)
{
	t_binary *bin;

	bin = (t_binary*)ft_memalloc(sizeof(t_binary));
	if (bin == NULL)
		error_msg_errno("Unable to allocate binary stream");
	bin->content = NULL;
	bin->header = NULL;
	bin->c_size = 0;
	bin->h_size = 0;
	return (bin);
}
