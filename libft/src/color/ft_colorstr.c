/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:06:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"
#include "ft_str.h"
#include "ft_strarr.h"

char	*ft_colorstr(int color)
{
	char	*str;
	char	**colors;

	if (color > 15 || color < 0)
		return (NULL);
	colors = ft_strarrdup_var(16, "black", "red", "green", "yellow", \
		"blue", "magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	if (colors == NULL)
		return (NULL);
	str = ft_strdup(colors[color]);
	ft_strarrdel(&colors);
	return (str);
}
