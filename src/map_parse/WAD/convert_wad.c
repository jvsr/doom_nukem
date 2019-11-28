/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_wad.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:28:58 by pholster       #+#    #+#                */
/*   Updated: 2019/11/28 17:24:19 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

#include "map.h"
#include "wad.h"
#include "game.h"
#include "error.h"
#include "campaign.h"

t_campaign *alloc_campaign(void)
{
	t_campaign *campaign;
	
	campaign = (t_campaign*)ft_memalloc(sizeof(t_campaign));
	if (campaign == NULL)
		error_msg_errno("Failed to alloc level");
	return (campaign);
}

void		convert_vertex(t_campaign *campaign, t_wad *wad)
{
	size_t	i;

	campaign->vertex = (t_coord*)ft_memalloc(sizeof(t_coord) * wad->levels->vertexes_amount);
	if (campaign->vertex == NULL)
		error_msg_errno("Failed to alloc level vertex");
	i = 0;
	while (i < wad->levels->vertexes_amount)
	{
		campaign->vertex[i].x = wad->levels->vertexes[i]->x;
		campaign->vertex[i].y = wad->levels->vertexes[i]->y;
		i++;
	}
}

void		convert_walls(t_campaign *campaign, t_wad *wad)
{
	size_t	i;

	campaign->wall = (t_campaign_wall**)ft_memalloc(sizeof(t_campaign_wall*) * wad->levels->linedefs_amount);
	if (campaign->wall == NULL)
		error_msg_errno("Failed to alloc level wall");
	i = 0;
	while (i < wad->levels->linedefs_amount)
	{
		campaign->wall[i] = (t_campaign_wall*)ft_memalloc(sizeof(t_campaign_wall));
		if (campaign->wall[i] == NULL)
			error_msg_errno("Failed to alloc level wall");
		campaign->wall[i]->vertex_begin = &campaign->vertex[wad->levels->linedefs[i]->vertex_begin];
		campaign->wall[i]->vertex_end = &campaign->vertex[wad->levels->linedefs[i]->vertex_end];
		// ft_printf("X: %f, Y: %f\n", campaign->wall[i]->vertex_begin->x, campaign->wall[i]->vertex_begin->y);
		// ft_printf("X: %f, Y: %f\n\n", campaign->wall[i]->vertex_end->x, campaign->wall[i]->vertex_end->y);
		i++;
	}	
}

t_campaign	*convert_wad(t_wad *wad, t_game *game)
{
	t_campaign	*campaign;

	campaign = alloc_campaign();
	convert_vertex(campaign, wad);
	convert_walls(campaign, wad);
	convert_dssound(wad, game);
	return (campaign);
}
