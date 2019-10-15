/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg_errno.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 13:37:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/03 13:37:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "error.h"

void	error_msg_errno(const char *msg)
{
	error_msg(strerror(errno), errno, msg);
}