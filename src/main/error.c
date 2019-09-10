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

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "libft/ft_printf.h"

void	error_msg(const char *msg, int error_code)
{
	ft_dprintf(2, "Error(%d): %s\n", error_code, msg);
	SDL_Quit();
	TTF_Quit();
	exit(error_code);
}
