/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrtostr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:39:20 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:03:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"
#include "ft_string.h"

char	*ft_chrtostr(char c)
{
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
