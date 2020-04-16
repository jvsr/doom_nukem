/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_button.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:43 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

/*
** * Gui internal function
*/

void		draw_button(SDL_Surface *dst, t_button *button, SDL_Point abs_dim)
{
	draw_image(dst, button->image);
	draw_text(dst, button->text, abs_dim);
}
