/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strishex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 14:56:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/04 14:56:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bool.h"
#include "ft_char.h"

t_bool	ft_strishex(const char *str)
{
	while (*str)
	{
		if (ft_ishex(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}
