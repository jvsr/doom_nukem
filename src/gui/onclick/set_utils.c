/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:48:57 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "setting.h"

void	set_float(float setting, t_transform *location, int precision)
{
	char *text;

	text = ft_strformat("%.*f", precision, setting);
	set_elem_text_str(location, text);
	free(text);
}

void	set_int(int setting, t_transform *location)
{
	char *text;

	text = ft_strformat("%d", setting);
	set_elem_text_str(location, text);
	free(text);
}
