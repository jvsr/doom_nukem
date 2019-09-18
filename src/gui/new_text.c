/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_text.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:06:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:56:09 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_memory.h"

#include "gui.h"
#include "error.h"

/*
** * Gui internal function
*/

t_text			*new_text(void)
{
	t_text *text;

	text = (t_text *)ft_memalloc(sizeof(t_text));
	if (text == NULL)
		error_msg(strerror(errno), errno, "Failed to alloc text");
	return (text);
}
