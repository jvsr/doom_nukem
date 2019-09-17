/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_image_color.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:41:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 16:41:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"

#include "gui.h"

void	set_image_color(t_image *image, SDL_Color color)
{
	ft_memcpy(&image->color, &color, sizeof(SDL_Color));
}
