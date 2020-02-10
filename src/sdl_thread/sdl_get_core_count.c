/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_get_core_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 14:04:58 by pholster       #+#    #+#                */
/*   Updated: 2020/02/09 14:04:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "sdl_thread.h"

ssize_t	sdl_get_core_count(void)
{
	return (sysconf(_SC_NPROCESSORS_ONLN));
}
