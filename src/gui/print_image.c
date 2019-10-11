/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_image.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 17:51:36 by pholster       #+#    #+#                */
/*   Updated: 2019/10/04 17:51:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"

#include "color.h"
#include "gui.h"

void	print_image(t_image *image)
{
	char	*color_hex;

	color_hex = color_to_hex(image->color, TRUE);
	ft_printf("Color: %s\nDraw method: %s\n",
	color_hex, get_draw_method_name(image->draw_method));
	free(color_hex);
}
