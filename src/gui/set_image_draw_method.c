/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_image_draw_method.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:41:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 16:41:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_image_draw_method(t_image *image, t_draw_method method)
{
	image->draw_method = method;
}
