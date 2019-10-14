/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ishex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 14:58:59 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/04 14:58:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bool.h"
#include "ft_char.h"

t_bool	ft_ishex(char c)
{
	if (ft_isdigit(c)
	|| (c >= 'a' && c <= 'f')
	|| (c >= 'A' && c <= 'F'))
		return (TRUE);
	return (FALSE);
}
