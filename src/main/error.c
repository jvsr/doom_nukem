/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:54:59 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/27 14:48:28 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_printf.h"

void	error_msg(const char *msg, int error_code)
{
	ft_dprintf(2, "Error(%d): %s", error_code, msg);
	exit(error_code);
}
