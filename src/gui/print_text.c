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
	ft_printf("Text:\n  Str: %s\n  Size: %.2f\n  \
Draw method: %s\n  Font type: %s\n",
	text->str, text->size, get_draw_method_name(text->draw_method),
	get_font_type_name(text->font_type));
}
