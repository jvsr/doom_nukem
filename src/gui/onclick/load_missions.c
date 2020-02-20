/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_missions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 15:09:03 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/19 21:08:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

#include "game.h"
#include "error.h"
#include "onclick.h"

static void		create_map_list(t_game *game)
{
	int			fd;
	int			forky;
	char *const	argument[] = {"/bin/ls", CAMPAIGN_PATH, NULL};

	forky = fork();
	if (forky == 0)
	{
		fd = open(TMP, O_CREAT | O_WRONLY,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
		if (fd == -1)
			error_msg_errno("Failed to open tmp file");
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
	(void)list;
	(void)game;
}

/*
**void	printlist(const t_list *list)
**{
**	ft_printf("item: %s\n", list->content);
**}
**ft_lstiter(maps, printlist);
*/

void			load_missions(t_game *game)
{
	static size_t	page = 0;
	t_list			*maps;
	t_list			*start;

	(void)page;
	create_map_list(game);
	maps = read_map_list();
	start = maps;
	add_maps(start, game);
}
