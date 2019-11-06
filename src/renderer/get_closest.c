/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_closest.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:27:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/06 14:27:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "game.h"
#include "map.h"
#include "renderer.h"
#include "shape.h"

static void		get_line_from_points(t_wall *wall, t_line *line)
{
	line->x = (wall->end.y - wall->start.y) / (wall->end.x - wall->start.x);
	line->equals = (line->x * wall->start.x) + wall->start.y;
	line->y = -1;
}

static float	solve_line(t_line *line, float x, float y)
{
	return ((line->x * x) + (line->y * y) + line->equals);
}

static t_bool	is_closer(t_line *line, t_wall *wall, t_vec *pos, t_bool *bool)
{
	float	vals[3];

	vals[0] = solve_line(line, wall->start.x, wall->start.y);
	vals[1] = solve_line(line, wall->end.x, wall->end.y);
	vals[2] = solve_line(line, pos->x, pos->y);
	if (vals[0] > -1 && vals[1] > -1 && vals[2] > -1)
	{
		*bool = FALSE;
		return (FALSE);
	}
	else if (vals[0] < 0 && vals[1] < 0 && vals[2] < 0)
	{
		*bool = FALSE;
		return (FALSE);
	}
	*bool = TRUE;
	return (TRUE);
}

static void		remove_from_list(t_list *walls, t_wall *wall)
{
	t_list	*prev;

	while (walls != NULL && walls->content != wall)
	{
		prev = walls;
		walls = walls->next;
	}
	prev->next = walls->next;
	walls->next = NULL;
	ft_lstdelone(&walls, NULL);
}

t_wall			*get_closest(t_list *walls, t_vec *pos)
{
	t_list  *sub_walls[2];
	t_wall  *final;
	
	t_bool	bool;
	t_line  cur;

	final = NULL;
	bool = TRUE;
	sub_walls[0] = walls;
	while (sub_walls[0])
	{
		final = sub_walls[0]->content;
		get_line_from_points(sub_walls[0]->content, &cur);
		sub_walls[1] = walls;
		while (sub_walls[1])
		{
			if (is_closer(&cur, sub_walls[1]->content, pos, &bool) == TRUE)
				break;
			sub_walls[1] = sub_walls[1]->next;
		}
		if (bool == FALSE)
			break;
		sub_walls[0] = sub_walls[0]->next;
	}
	remove_from_list(walls, final);
	return (final);
}
