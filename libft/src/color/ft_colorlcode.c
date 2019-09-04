/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorlcode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:05:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include "ft_string.h"
#include "ft_stringarray.h"

ssize_t		ft_colorlcode(const char *str)
{
	char	**colors;
	size_t	i;

	i = 16;
	colors = ft_strarrdup_var(i, "black", "red", "green", "yellow", \
		"blue", "magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	if (colors == NULL)
		return (-1);
	while (i > 0)
	{
		i--;
		if (ft_strnequ_nocase(str, colors[i], ft_strlen(colors[i])))
		{
			ft_strarrdel(&colors);
			return (i);
		}
	}
	ft_strarrdel(&colors);
	return (-1);
}
