/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_gametime.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 13:23:17 by euan           #+#    #+#                */
/*   Updated: 2019/09/24 13:23:17 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gametime.h"

t_uint64		get_gametime(t_time *time)
{
	return ((t_uint64)(((double)(clock() - *time)) / CLOCKS_PER_MILLI));
}
