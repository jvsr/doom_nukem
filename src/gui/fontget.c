/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fontget.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:38:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/03 10:40:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

TTF_Font	*fontget(t_gui *ui, t_fonttype font)
{
	if (font == ROBOTO)
		return (ui->font[0]);
	else
		return (ui->font[1]);
}
