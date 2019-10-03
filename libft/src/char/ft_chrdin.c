/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:40:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

t_bool		ft_chrdin(const char *str, const char *dlm)
{
	return (ft_chrdindex(str, dlm) != -1);
}
