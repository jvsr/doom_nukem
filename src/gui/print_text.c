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

#include "color.h"
#include "gui.h"

void	print_text(t_text *text)
{
	char	*color_hex;

	color_hex = color_to_hex(text->color, TRUE);
	ft_printf("Text: %s\nSize: %.2f\nColor: %s\n\
Draw method: %s\nFont type: %s\n",
	text->text, text->size, color_hex,
	get_draw_method_name(text->draw_method),
	get_font_type_name(text->font_type));
	free(color_hex);
}
