/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_button.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 17:51:36 by pholster       #+#    #+#                */
/*   Updated: 2019/10/04 17:51:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

void	print_button(t_button *button)
{
	print_text(button->text);
	print_image(button->image);
}
