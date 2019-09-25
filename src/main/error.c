/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:54:59 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 11:12:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_printf.h"

void	error_msg(const char *error_msg, int error_code, const char *msg)
{
	ft_dprintf(2, "doom-nukem: Error(%d) - %s (%s)\n",
	error_code, msg, error_msg);
	TTF_Quit();
	SDL_Quit();
	exit(error_code);
}

void	error_msg_errno(const char *msg)
{
	error_msg(strerror(errno), errno, msg);
}

void	error_msg_sdl(int error_code, const char *msg)
{
	error_msg(SDL_GetError(), error_code, msg);
}
