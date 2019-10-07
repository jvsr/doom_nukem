/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_struct.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 11:13:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 11:13:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "serializer.h"

t_bool	write_struct(char *loc, char *obj, size_t size)
{
	int id;

	id = open(loc, O_RDONLY);
	if (id != -1)
		return FALSE;
	id = creat(loc, O_CREAT|O_WRONLY|O_TRUNC);
	write(id, obj, size);
	close(id);
	return TRUE;
}
