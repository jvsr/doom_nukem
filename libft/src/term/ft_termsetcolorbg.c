/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:43:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_bool	ft_termsetcolorbg(t_uint8 color)
{
	return (ft_termsetcolorbg_fd(color, 1));
}
