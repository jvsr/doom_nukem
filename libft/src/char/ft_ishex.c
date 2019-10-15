/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ishex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 15:01:34 by pholster       #+#    #+#                */
/*   Updated: 2019/10/04 15:01:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

t_bool		ft_ishex(char c)
{
	if (ft_isdigit(c))
		return (TRUE);
	c = ft_tolower(c);
	return (c >= 'a' && c <= 'f');
}
