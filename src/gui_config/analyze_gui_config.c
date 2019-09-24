/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analyze_gui_config.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 17:45:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 14:07:50 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "libft/ft_string.h"

#include "gui.h"
#include "lex.h"
#include "error.h"
#include "gui_config.h"

t_panel		*analyze_gui_config(const char *state_name, const char *file_name)
{
	t_panel		*result;
	t_token		*tokens;
	const int	fd = open_gui_config(file_name);

	result = NULL;
	tokens = lex_gui_config(fd);
	(void)tokens;
	(void)state_name;
	close(fd);
	return (result);
}
