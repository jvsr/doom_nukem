/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_to_rgba.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:14:59 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 11:36:32 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_uint32	hex_to_rgba(char *hex)
{
	SDL_Color	color;

	hex_to_color(&color, hex);
	return (color_to_rgba(color));
}
