/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_gametime.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 13:28:26 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:06:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "gametime.h"
#include "error.h"

void		init_gametime(t_time *time)
{
	if (gettimeofday(time, NULL) == -1)
		error_msg_errno("Failed to init gametime");
}
