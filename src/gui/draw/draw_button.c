/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_button.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:58:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

/*
** * Gui internal function
*/

void		draw_button(SDL_Surface *dst, t_button *button, t_gui *ui)
{
	draw_image(dst, button->image);
	draw_text(dst, button->text, ui);
}
