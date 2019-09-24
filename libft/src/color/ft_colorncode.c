/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorncode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:05:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include "ft_str.h"
#include "ft_strarr.h"

int		ft_colorncode(const char *str, size_t n)
{
	char	**colors;

	if (n > 16)
		n = 16;
	colors = ft_strarrdup_var(n, "black", "red", "green", "yellow", \
		"blue", "magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	if (colors == NULL)
		return (-1);
	while (n > 0)
	{
		n--;
		if (ft_strequ_nocase(str, colors[n]))
		{
			ft_strarrdel(&colors);
			return (n);
		}
	}
	ft_strarrdel(&colors);
	return (-1);
}
