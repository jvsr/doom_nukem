/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg_sdl.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:54:59 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 11:12:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "error.h"

void	error_msg_sdl(int error_code, const char *msg)
{
	error_msg(SDL_GetError(), error_code, msg);
}
