/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 15:12:17 by pholster       #+#    #+#                */
/*   Updated: 2019/09/06 14:50:26 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <criterion/criterion.h>
#include "gui.h"
#include "game.h"
#include "init.h"

Test(init, null) {
	t_game	*game = init();
	cr_assert(game->state == running);
	SDL_DestroyWindow(game->window);
}
