/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_gametime.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 13:23:17 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:06:51 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "gametime.h"
#include "error.h"

t_uint64		get_gametime(t_time *time)
{
	t_uint64	result;
	t_time		passed_time;

	if (gettimeofday(&passed_time, NULL) == -1)
		error_msg_errno("Failed to get gametime");
	passed_time.tv_sec -= time->tv_sec;
	passed_time.tv_usec -= time->tv_usec;
	if (passed_time.tv_usec < 0)
	{
		passed_time.tv_sec--;
		passed_time.tv_usec += 1000000;
	}
	result = (passed_time.tv_sec * 1000) + ((float)passed_time.tv_usec / 1000);
	return (result);
}
