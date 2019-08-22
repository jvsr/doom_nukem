/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:40:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"

t_bool		ft_chrin(char *str, int c)
{
	return (ft_chrindex(str, c) != -1);
}
