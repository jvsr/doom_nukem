/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkclick.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 11:39:35 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 16:06:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>

#include "libft/ft_list.h"
#include "libft/ft_string.h"
#include "libft/ft_memory.h"

#include "init.h"
#include "gui.h"
#include "game.h"
#include "init.h"

static t_bool	checkcolision(int x, int y, SDL_Point locs[2])
{
	return (x > locs[0].x && x < locs[1].x && y > locs[0].y && y < locs[1].y);
}

static void		getstart(t_transform *transform, SDL_Point *point)
{
	point->x = transform->position.x * INIT_WIDTH;
	point->y = transform->position.y * INIT_HEIGHT;
}

static void		getend(t_transform *transform, SDL_Point *point)
{
	if (transform->guitype == BUTTON)
	{
		point->x = ((t_button*)transform->guielem)->size.x * INIT_WIDTH;
		point->y = ((t_button*)transform->guielem)->size.y * INIT_HEIGHT;
	}
	else if (transform->guitype == IMAGE)
	{
		point->x = ((t_image*)transform->guielem)->size.x * INIT_WIDTH;
		point->y = ((t_image*)transform->guielem)->size.y * INIT_HEIGHT;
	}
	else if (transform->guitype == TEXT)
	{
		point->x = ((t_text*)transform->guielem)->font.size * INIT_WIDTH;
		point->y = ((t_text*)transform->guielem)->font.size * INIT_HEIGHT;
	}
	else if (transform->guitype == PANEL)
	{
		point->x = ((t_panel*)transform->guielem)->size.x * INIT_WIDTH;
		point->y = ((t_panel*)transform->guielem)->size.y * INIT_HEIGHT;
	}
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

void			checkclick(t_game *game, SDL_Point mpos)
{
	t_list		*lst;
	SDL_Point	locs[2];
	t_transform *cur;

	if (!game->cursoractive)
		return ;
	cur = NULL;
	lst = game->ui.onclicks;
	ft_bzero(locs, sizeof(locs));
	while (lst != NULL)
	{
		if (((t_transform*)lst->content)->visible == TRUE)
		{
			getstart((t_transform*)lst->content, &locs[0]);
			getend((t_transform*)lst->content, &locs[1]);
			locs[1] = (SDL_Point){locs[0].x + locs[1].x, locs[0].y + locs[1].y};
			if (checkcolision(mpos.x, mpos.y, locs) &&
				isabove(cur, lst->content))
				cur = ((t_transform*)lst->content);
		}
		lst = lst->next;
	}
	if (cur != NULL)
		cur->onclick(game, cur);
}
