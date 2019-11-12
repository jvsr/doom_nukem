/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analyze_gui_config.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 17:45:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 15:37:49 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <limits.h>

#include "libft/ft_str.h"

#include "game.h"
#include "gui.h"
#include "lex.h"
#include "parse.h"
#include "error.h"
#include "gui_config.h"

static void	empty_file_error(const char *file_name)
{
	char	full_path[PATH_MAX];

	ft_strcpy(full_path, g_doom_dir);
	ft_strcat(full_path, UI_CONFIG_PATH);
	ft_strcat(full_path, file_name);
	error_msg("GUI Error", 20,
		ft_strformat("Empty GUI config file: %s.ui.yml", full_path));
}

t_transform	*analyze_gui_config(t_gui *ui, const char *file_name)
{
	t_transform		*result;
	t_token			*tokens;
	t_parse_info	*parse_info;
	const int		fd = open_gui_config(file_name);

	result = NULL;
	tokens = lex_gui_config(fd);
	close(fd);
	if (tokens == NULL)
		empty_file_error(file_name);
	parse_info = parse_gui_config(tokens);
	result = exec_gui_config(ui, parse_info);
	return (result);
}
