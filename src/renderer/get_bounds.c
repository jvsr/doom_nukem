/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_bounds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 15:57:33 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 15:32:39 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"

static void	init_hit(t_hitem *hit, t_player *player, float tanvfov2)
{
	hit->st.y = hit->hit.dist * tanvfov2;
	hit->y.x = player->height + player->heightoffset;
	hit->y.y = hit->y.x + hit->st.y;
	hit->y.x -= hit->st.y;
	hit->st.x = hit->st.y * 2;
}

SDL_Point	get_bounds(t_player *player,
						SDL_Surface *dst, t_hitem *hit, float tanvfov2)
{
	SDL_Point	new;

	init_hit(hit, player, tanvfov2);
	hit->hoffset = (player->heightoffset / hit->st.x) * dst->h;
	new = (SDL_Point){0, 0};
	if (!hit->hit.wall->is_portal && hit->hit.sect->ceil >
		hit->y.x && hit->hit.sect->floor < hit->y.y)
	{
		new.x = (((hit->hit.sect->floor - hit->y.x) / hit->st.x) *
				dst->h) - player->screen_updown;
		new.y = dst->h - (((hit->y.y - hit->hit.sect->ceil) / hit->st.x) *
				dst->h) - player->screen_updown;
	}
	else if (hit->hit.sect->ceil > hit->y.x &&
		hit->hit.sect->floor < hit->y.y && hit->hit.wall->window)
	{
		new.x = (((hit->hit.wall->window->floor - hit->y.x) / hit->st.x) *
				dst->h) - player->screen_updown;
		new.y = dst->h - (((hit->y.y - hit->hit.wall->window->ceil) / hit->st.x)
				* dst->h) - player->screen_updown;
	}
	return (new);
}
