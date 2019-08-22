/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbool.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:10:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:40:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bool.h"

t_bool	ft_putbool(t_bool boolean)
{
	return (ft_putbool_fd(boolean, 1));
}
