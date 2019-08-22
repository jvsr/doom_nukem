/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:47:13 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:03:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"
#include "ft_string.h"

/*
** int		ft_getchar(void)
** {
** 	static int	pointer;
** 	static char	*str = NULL;
**
** 	if (str == NULL)
** 		ft_getnextline(1, &str);
** 	else if (str[pointer] == '\0')
** 	{
** 		ft_strdel(&str);
** 		pointer = 0;
** 		return ('\n');
** 	}
** 	else
** 		pointer++;
** 	return (str[pointer]);
** }
*/

int		ft_getchar(void)
{
	char	*str;

	ft_getnextline(1, &str);
	if (str[0] == '\0')
		str[0] = '\n';
	return (str[0]);
}
