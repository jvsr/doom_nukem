/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_text.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 17:51:36 by pholster       #+#    #+#                */
/*   Updated: 2019/10/04 17:51:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"

#include "gui.h"

void	print_text(t_text *text)
{
	ft_printf("Text:\n  Str: %s\n  Size: %.2f\n\
  Draw method: %d\n  Font type: %d\n",
	text->str, text->size,
	text->draw_method, text->font_type);
}
