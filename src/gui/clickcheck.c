/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clickcheck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 11:39:35 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 13:34:52 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "game.h"
#include "gui.h"
#include "init.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

static t_bool	checkcolision(int x, int y, t_pixel locs[2])
{
	return (x > locs[0].x && x < locs[1].x && y > locs[0].y && y < locs[1].y);
}

static t_pixel	getstart(t_transform *transform)
{
	return ((t_pixel){(transform->position.x * INIT_WIDTH),
	transform->position.y * INIT_HEIGHT});
}

static t_pixel	getend(t_transform *transform)
{
	if (transform->guitype == BUTTON)
		return ((t_pixel){((t_button*)transform->guielem)->size.x * INIT_WIDTH,
		((t_button*)transform->guielem)->size.y * INIT_HEIGHT});
	else if (transform->guitype == IMAGE)
		return ((t_pixel){((t_image*)transform->guielem)->size.x * INIT_WIDTH,
		((t_image*)transform->guielem)->size.y * INIT_HEIGHT});
	else if (transform->guitype == TEXT)
		return ((t_pixel){((t_text*)transform->guielem)->font.size * INIT_WIDTH,
		((t_text*)transform->guielem)->font.size * INIT_HEIGHT});
	else
		return ((t_pixel){((t_panel*)transform->guielem)->size.x * INIT_WIDTH,
		((t_panel*)transform->guielem)->size.y * INIT_HEIGHT});
	return ((t_pixel){0, 0});
}

static t_bool	isabove(t_transform *cur, t_transform *new)
{
	if (cur == NULL)
		return (TRUE);
	if (new == NULL)
		return (FALSE);
	while (cur->parent != NULL && new->parent != NULL &&
		ft_strequ(cur->parent->name, new->parent->name) == FALSE)
	{
		cur = cur->parent;
		new = new->parent;
	}
	return (new->layer > cur->layer);
}

void			clickcheck(t_game *game)
{
	int			x;
	int			y;
	t_list		*lst;
	t_pixel		locs[2];
	t_transform *cur;

	cur = NULL;
	SDL_GetMouseState(&x, &y);
	lst = game->ui.onclicks;
	while (lst != NULL)
	{
		if (((t_transform*)lst->content)->visible == TRUE)
		{
			locs[0] = getstart((t_transform*)lst->content);
			locs[1] = getend((t_transform*)lst->content);
			locs[1] = (t_pixel){locs[0].x + locs[1].x, locs[0].y + locs[1].y};
			if (checkcolision(x, y, locs) && isabove(cur, lst->content))
				cur = ((t_transform*)lst->content);
		}
		lst = lst->next;
	}
	if (cur != NULL)
		cur->onclick(game, cur);
}
