/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_image.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 17:51:36 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"

#include "color.h"
#include "gui.h"

void	print_image(t_image *image)
{
	char	*color_hex;

	color_hex = color_to_hex(image->color, TRUE);
	ft_printf("Texture: %p\nColor: %s\nDraw method: %s\n",
		image->texture, color_hex, get_draw_method_name(image->draw_method));
	free(color_hex);
}
