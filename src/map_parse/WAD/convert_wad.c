/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_wad.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:28:58 by pholster       #+#    #+#                */
/*   Updated: 2019/11/25 17:28:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "wad.h"
#include "game.h"

void	convert_wad(t_wad *wad, t_game *game)
{
	convert_dssound(wad, game);
}
