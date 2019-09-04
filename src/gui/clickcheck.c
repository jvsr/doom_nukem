/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clickcheck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 11:39:35 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 14:12:49 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "gui.h"
#include "libft/ft_list.h"

static t_bool	checkcolision(int x, int y, t_pixel locs[2])
{
	return (x > locs[0].x && x < locs[1].x && y > locs[0].y && y < locs[1].y);
}

static t_pixel	getstart(t_transform *transform)
{
	return ((t_pixel){(transform->position.x * INITWIDTH),
	transform->position.y * INITHEIGHT});
}

static t_pixel	getend(t_transform *transform)
{
	if (transform->guitype == BUTTON)
		return ((t_pixel){((t_button*)transform->guielem)->size.x * INITWIDTH,
		((t_button*)transform->guielem)->size.y * INITHEIGHT});
	else if (transform->guitype == IMAGE)
		return ((t_pixel){((t_image*)transform->guielem)->size.x * INITWIDTH,
		((t_image*)transform->guielem)->size.y * INITHEIGHT});
	else if (transform->guitype == TEXT)
		return ((t_pixel){((t_text*)transform->guielem)->font.size * INITWIDTH,
		((t_text*)transform->guielem)->font.size * INITHEIGHT});
	else
		return ((t_pixel){((t_panel*)transform->guielem)->size.x * INITWIDTH,
		((t_panel*)transform->guielem)->size.y * INITHEIGHT});
	return ((t_pixel){0, 0});
}

void			clickcheck(t_game *game)
{
	int		x;
	int		y;
	t_list	*lst;
	t_pixel	locs[2];

	SDL_GetMouseState(&x, &y);
	lst = game->ui.onclicks;
	while (lst != NULL)
	{
		if (((t_transform*)lst->content)->visible == TRUE)
		{
			locs[0] = getstart((t_transform*)lst->content);
			locs[1] = getend((t_transform*)lst->content);
			locs[1] = (t_pixel){locs[0].x + locs[1].x, locs[0].y + locs[1].y};
			printf("Loc 0 -> %i, %i\n", locs[0].x, locs[0].y);
			printf("Loc 1 -> %i, %i\n", locs[1].x, locs[1].y);
			printf("Mouse -> %i, %i\n", x, y);
			if (checkcolision(x, y, locs))
			{
				printf("Here\n");
				((t_transform*)lst->content)->onclick(game,
					(t_transform*)lst->content);
				return ;
			}
		}
		lst = lst->next;
	}
}
