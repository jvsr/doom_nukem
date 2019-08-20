/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_pututf8(t_wchar c)
{
	return (ft_pututf8_fd(c, 1));
}
