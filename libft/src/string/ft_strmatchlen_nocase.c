/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmatchlen_nocase.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 17:23:15 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:37:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_character.h"

size_t	ft_strmatchlen_nocase(char *str1, char *str2)
{
	size_t			i;
	unsigned char	temp_a;
	unsigned char	temp_b;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	temp_a = ft_tolower(str1[i]);
	while (temp_a != '\0')
	{
		temp_b = ft_tolower(str2[i]);
		if (temp_a != temp_b)
			return (i);
		i++;
	}
	return (i);
}
