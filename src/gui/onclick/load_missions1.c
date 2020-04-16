/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_missions1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 12:33:38 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 12:34:07 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "gui.h"
#include "game.h"
#include "error.h"
#include "onclick.h"

void			remove_maps(t_game *game)
{
	int			i;
	char		*name;
	t_transform	*level;

	i = 1;
	while (i <= 8)
	{
		name = ft_strformat("level%d", i);
		level = get_gui_child(game->ui, name);
		set_elem_text_str(level, "");
		free(name);
		i++;
	}
}

t_bool			get_focus(t_game *game)
{
	const t_transform *camp = get_gui_child(game->ui, "missionsCampaignButton");
	const t_transform *custom = get_gui_child(game->ui, "missionsCustomButton");

	if (camp->layer > custom->layer)
		return (TRUE);
	return (FALSE);
}

t_list			*skip_page(t_list *maps, size_t page)
{
	size_t			i;
	const	size_t	item = page * 8;

	i = 0;
	while (i < item && maps != NULL)
	{
		i++;
		maps = maps->next;
	}
	return (maps);
}
