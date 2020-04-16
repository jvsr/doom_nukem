/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_gui.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 20:21:45 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:08:51 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "error.h"

static t_gui	*alloc_ui(void)
{
	t_gui	*ui;

	ui = (t_gui *)ft_memalloc(sizeof(t_gui));
	if (ui == NULL)
		error_msg_errno("Failed to alloc UI");
	return (ui);
}

static TTF_Font	*open_font(const char *file_name, char const *exec_path)
{
	TTF_Font	*font;
	char		full_path[PATH_MAX];

	ft_strcpy(full_path, exec_path);
	ft_strcat(full_path, FONT_PATH);
	ft_strcat(full_path, file_name);
	font = TTF_OpenFont(full_path, 50);
	if (font == NULL)
		error_msg_sdl(23, ft_strformat("Failed to open %s", full_path));
	return (font);
}

static void		init_fonts(t_gui *ui, char const *exec_path)
{
	ui->fonts[0] = open_font("Roboto-Regular.ttf", exec_path);
	ui->fonts[1] = open_font("monof55.ttf", exec_path);
	ui->fonts[2] = open_font("ka1.ttf", exec_path);
	ui->fonts[3] = open_font("Foul-Fiend.ttf", exec_path);
	ui->fonts[4] = open_font("NECK-ROMANCER-Regular.ttf", exec_path);
}

void			init_gui(t_game *game)
{
	t_gui	*ui;

	ui = alloc_ui();
	game->ui = ui;
	ui->window_surface = game->surface;
	ui->mission_page = 0;
	init_fonts(ui, game->exec_path);
}
