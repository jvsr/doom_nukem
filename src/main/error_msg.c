/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 13:34:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/03 13:34:48 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "libft/ft_printf.h"

#include "game.h"

void	error_msg(const char *error_msg, int error_code, const char *msg)
{
	ft_dprintf(2, "doom-nukem: Error(%d) - %s (%s)\n",
	error_code, msg, error_msg);
	quit(error_code);
}
