/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_gui.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 20:21:45 by pholster       #+#    #+#                */
/*   Updated: 2019/09/10 20:21:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_memory.h"

#include "gui.h"
#include "game.h"
#include "error.h"

static t_gui	*alloc_ui(void)
{
	t_gui	*ui;

	ui = (t_gui *)ft_memalloc(sizeof(t_gui));
	if (ui == NULL)
		error_msg(strerror(errno), errno, "Failed to alloc UI");
	return (ui);
}

static void		init_fonts(t_gui *ui)
{
	ui->fonts[0] = TTF_OpenFont("fonts/Roboto-Regular.ttf", 50);
	ui->fonts[1] = TTF_OpenFont("fonts/monof55.ttf", 50);
	ui->fonts[2] = TTF_OpenFont("fonts/ka1.ttf", 50);
}

void			init_gui(t_game *game)
{
	t_gui	*ui;

	ui = alloc_ui();
	game->ui = ui;
	ui->window_surface = game->surface;
	init_fonts(ui);
}
