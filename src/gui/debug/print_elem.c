/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_elem.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 17:31:18 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:26 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_char.h"
#include "libft/ft_printf.h"

#include "gui_internal.h"

static void	print_gui_elem(t_transform *elem, t_bool print_children)
{
	if (elem->gui_type == TEXT)
		print_text(elem->gui_elem.text);
	else if (elem->gui_type == IMAGE)
		print_image(elem->gui_elem.image);
	else if (elem->gui_type == BUTTON)
		print_button(elem->gui_elem.button);
	else if (elem->gui_type == PANEL)
		print_panel(elem->gui_elem.panel, print_children);
}

void		print_elem(t_transform *elem, t_bool print_children)
{
	const char	*gui_type_name = get_gui_type_name(elem->gui_type);
	const char	*gui_onclick_name = get_onclick_name(elem->onclick);

	ft_printf("%{yellow}Name: %s\nType: %s%{}\nShow: %hhd\nLayer: %hd\n\
Pos: %.4f %.4f\nDim: %.4f %.4f\n\
Has_alpha: %d\nClickable: %hhd\nOnclick: %s\n",
	elem->name, gui_type_name, elem->show, elem->layer,
	elem->pos.x, elem->pos.y, elem->dim.x, elem->dim.y,
	elem->has_alpha, elem->clickable, gui_onclick_name);
	print_gui_elem(elem, print_children);
	if (elem->next != NULL)
		ft_putchar('\n');
	ft_strdel((char**)&gui_type_name);
	ft_strdel((char**)&gui_onclick_name);
}
