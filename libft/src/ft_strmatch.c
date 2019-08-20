/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmatch.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:44:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/18 17:57:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

t_bool	ft_strmatch(const char *str, const char *needle)
{
	if (str == NULL || needle == NULL)
		return (FALSE);
	if (needle[0] == '\0' && str[0] == '\0')
		return (TRUE);
	if (needle[0] != str[0] && needle[0] != '*')
		return (FALSE);
	if (needle[0] == '*' && str[0] != '\0')
	{
		return (ft_strmatch(&str[1], &needle[1]) ||
				ft_strmatch(&str[1], &needle[0]) ||
				ft_strmatch(&str[0], &needle[1]));
	}
	return (ft_strmatch(&str[1], &needle[1]));
}
