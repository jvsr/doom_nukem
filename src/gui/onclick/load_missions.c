/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_missions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 15:09:03 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/20 13:29:00 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "gui.h"
#include "game.h"
#include "error.h"
#include "onclick.h"

static void		create_map_list(t_game *game, char *path)
{
	int			fd;
	int			forky;
	char *const	argument[] = {"/bin/ls", path, NULL};

	forky = fork();
	if (forky == 0)
	{
		fd = open(TMP, O_CREAT | O_WRONLY | O_TRUNC);
		if (fd == -1)
			error_msg_errno("Failed to open tmp file");
		chmod(TMP, S_IRWXU);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
		close(fd);
		execve(argument[0], argument, game->envp);
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
}

static t_bool	cmp_list(const t_list *l1, const t_list *l2)
{
	if (ft_strcmp_nocase((char*)l1->content, (char*)l2->content) > 0)
		return (TRUE);
	return (FALSE);
}

static t_list	*read_map_list(void)
{
	int		fd;
	char	*line;
	t_list	*new;
	t_list	*maps;

	maps = NULL;
	fd = open(TMP, O_RDONLY);
	if (fd == -1)
		error_msg_errno("Failed to open tmp file");
	while (ft_getnextline(fd, &line) > 0)
	{
		if (ft_strequ(ft_strrchr(TMP, '/') + 1, line) == FALSE)
		{
			new = ft_lstnew(line, ft_strlen(line));
			if (new == NULL)
				error_msg_errno("Failed to alloc List");
			ft_lstadd(&maps, new);
		}
	}
	close(fd);
	ft_lstsort(&maps, cmp_list);
	return (maps);
}

static void		add_maps(t_list *list, t_game *game)
{
	int			i;
	char		*name;
	t_transform	*level;

	i = 1;
	while (list != NULL)
	{
		name = ft_strformat("level%d", i);
		level = get_gui_child(game->ui, name);
		set_elem_text_str(level, list->content);
		free(name);
		list = list->next;
		i++;
	}
}

void		remove_maps(t_game *game)
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

/*
**void	printlist(const t_list *list)
**{
**	ft_printf("item: %s\n", list->content);
**}
**ft_lstiter(maps, printlist);
*/

t_bool			get_focus(t_game *game)
{
	const t_transform *camp = get_gui_child(game->ui, "missionscampaignbutton");
	const t_transform *custom = get_gui_child(game->ui, "missionscustombutton");

	if (camp->layer > custom->layer)
		return (TRUE);
	return (FALSE);
}

void			del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void			load_missions(t_game *game)
{
	static size_t	page = 0;
	t_bool			focus;
	t_list			*maps;
	t_list			*start;

	(void)page;
	focus = get_focus(game);
	ft_printf("%d\n", focus);
	if (focus == TRUE)
		create_map_list(game, CAMPAIGN_PATH);
	else if (focus == FALSE)
		create_map_list(game, CUSTOM_PATH);
	maps = read_map_list();
	start = maps;
	add_maps(start, game);
	ft_lstdel(&maps, del);
}
