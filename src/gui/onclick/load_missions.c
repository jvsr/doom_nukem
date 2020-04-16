/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_missions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 15:09:03 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/08 16:58:41 by euan          ########   odam.nl         */
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

void			create_map_list(t_game *game, char *path)
{
	int			fd;
	int			forky;
	char *const	argument[3] = {"/bin/ls", path, NULL};

	forky = fork();
	if (forky == 0)
	{
		fd = open(TMP, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
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

t_list			*read_map_list(void)
{
	int		fd;
	char	*line;
	t_list	*new;
	t_list	*maps;

	maps = NULL;
	line = NULL;
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
	ft_strdel(&line);
	ft_lstsort(&maps, cmp_list);
	return (maps);
}

static void		add_maps(t_list *list, t_game *game)
{
	int			i;
	char		*name;
	t_transform	*level;

	i = 1;
	while (list != NULL && i <= 8)
	{
		name = ft_strformat("level%d", i);
		level = get_gui_child(game->ui, name);
		set_elem_text_str(level, list->content);
		free(name);
		list = list->next;
		i++;
	}
}

void			load_missions(t_game *game)
{
	t_bool			focus;
	t_list			*maps;
	t_list			*start;

	focus = get_focus(game);
	if (focus == TRUE)
		create_map_list(game, CAMPAIGN_PATH);
	else if (focus == FALSE)
		create_map_list(game, CUSTOM_PATH);
	maps = read_map_list();
	start = skip_page(maps, game->ui->mission_page);
	add_maps(start, game);
	ft_lstdel(&maps, ft_lstdelmem);
}
