/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_font.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:38:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 13:38:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

TTF_Font	*get_font(TTF_Font **fonts, t_font_type font)
{
	return (fonts[font]);
}
