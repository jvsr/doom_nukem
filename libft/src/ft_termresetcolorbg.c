/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termresetcolorbg.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termresetcolorbg(void)
{
	ft_termresetcolorbg_fd(1);
}
