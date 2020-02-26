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
#include "error.h"

t_uint64		get_gametime(t_time *time)
{
	t_time		current_time;
	t_time		passed_time;

	if (gettimeofday(&current_time, NULL) == -1)
		error_msg_errno("Failed to get gametime");
	timersub(&current_time, time, &passed_time);
	return ((t_uint64)(passed_time.tv_sec * 1000) + (passed_time.tv_usec / 1000));
}
