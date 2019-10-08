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

#include "gui.h"

void	print_image(t_image *image)
{
	ft_printf("Image:\n  Draw method: %s\n",
	get_draw_method_name(image->draw_method));
}
