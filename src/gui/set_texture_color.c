/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_texture_color.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:41:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 16:41:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"

#include "gui.h"

void	set_texture_color(SDL_Color *dst, SDL_Color color)
{
	ft_memcpy(dst, &color, sizeof(SDL_Color));
}
