/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textdestroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:44:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:47:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		textdestroy(t_text *text)
{
	ft_strdel(&text->text);
	ft_lstdel(&text->transform.children, NULL);
	free(text);
	text = NULL;
}
