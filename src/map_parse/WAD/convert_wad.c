/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_wad.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:28:58 by pholster       #+#    #+#                */
/*   Updated: 2019/12/04 17:38:12 by jvisser       ########   odam.nl         */
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

void		convert_sidedefs(t_campaign *campaign, t_wad *wad)
{
	size_t	i;

	campaign->sidedef_amount = wad->levels->sidedefs_amount;
	campaign->sidedef = (t_campaign_sidedef**)ft_memalloc(sizeof(t_campaign_sidedef*) * wad->levels->sidedefs_amount);
	if (campaign->sidedef == NULL)
		error_msg_errno("Failed to alloc level sidedef");
	i = 0;
	while (i < wad->levels->linedefs_amount)
	{
		campaign->sidedef[i] = (t_campaign_sidedef*)ft_memalloc(sizeof(t_campaign_sidedef));
		if (campaign->sidedef[i] == NULL)
			error_msg_errno("Failed to alloc level sidedef");
		campaign->sidedef[i]->offset_x = wad->levels->sidedefs[i]->offset_x;
		campaign->sidedef[i]->offset_y = wad->levels->sidedefs[i]->offset_y;

		campaign->sidedef[i]->texture_up = wad->levels->sidedefs[i]->texture_up;
		campaign->sidedef[i]->texture_mid = wad->levels->sidedefs[i]->texture_mid;
		campaign->sidedef[i]->texture_low = wad->levels->sidedefs[i]->texture_low;
		campaign->sidedef[i]->sector = wad->levels->sidedefs[i]->sector;
		// ft_printf("X: %f, Y: %f\n", campaign->sidedef[i]->offset_x, campaign->sidedef[i]->offset_y);
		// ft_printf("TEXTURE\nUP: %s\nMID: %s\nLOW: %s\n", campaign->sidedef[i]->texture_up, campaign->sidedef[i]->texture_mid, campaign->sidedef[i]->texture_low);
		i++;
	}	
}

void		convert_walls(t_campaign *campaign, t_wad *wad)
{
	size_t	i;

	campaign->wall_amount = wad->levels->linedefs_amount;
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
		campaign->wall[i]->sidedef_right = campaign->sidedef[wad->levels->linedefs[i]->sidedef_right];
		campaign->wall[i]->sidedef_left = campaign->sidedef[wad->levels->linedefs[i]->sidedef_left];
		campaign->wall[i]->sector_tag = wad->levels->linedefs[i]->sector_tag;

		// ft_printf("X: %f, Y: %f\n", campaign->wall[i]->vertex_begin->x, campaign->wall[i]->vertex_begin->y);
		// ft_printf("X: %f, Y: %f\n", campaign->wall[i]->vertex_end->x, campaign->wall[i]->vertex_end->y);
		// if (campaign->wall[i]->sidedef_right) {
		// 	ft_printf("R_SIDE X: %d, Y: %d\n", campaign->wall[i]->sidedef_right->offset_x, campaign->wall[i]->sidedef_right->offset_y);
		// 	ft_printf("TEXTURE\nUP: %s\nMID: %s\nLOW: %s\n", campaign->wall[i]->sidedef_right->texture_up, campaign->wall[i]->sidedef_right->texture_mid, campaign->wall[i]->sidedef_right->texture_low);
		// }
		// if (campaign->wall[i]->sidedef_left) {
		// 	ft_printf("L_SIDE X: %d, Y: %d\n", campaign->wall[i]->sidedef_left->offset_x, campaign->wall[i]->sidedef_left->offset_y);
		// 	ft_printf("TEXTURE\nUP: %s\nMID: %s\nLOW: %s\n", campaign->wall[i]->sidedef_left->texture_up, campaign->wall[i]->sidedef_left->texture_mid, campaign->wall[i]->sidedef_right->texture_low);
		// }
		// ft_printf("\n");

		i++;
	}	
}

void		convert_sectors(t_campaign *campaign, t_wad *wad)
{
	size_t	i;

	campaign->sector_amount = wad->levels->sectors_amount;
	campaign->sector = (t_campaign_sector**)ft_memalloc(sizeof(t_campaign_sector*) * wad->levels->linedefs_amount);
	if (campaign->sector == NULL)
		error_msg_errno("Failed to alloc level sector");
	i = 0;
	while (i < wad->levels->sectors_amount)
	{
		campaign->sector[i] = (t_campaign_sector*)ft_memalloc(sizeof(t_campaign_sector));
		if (campaign->sector[i] == NULL)
			error_msg_errno("Failed to alloc level sector");
		campaign->sector[i]->sector_id = i;
		campaign->sector[i]->height_floor = wad->levels->sectors[i]->height_floor;
		campaign->sector[i]->height_ceiling = wad->levels->sectors[i]->height_ceiling;
		campaign->sector[i]->height_wall = campaign->sector[i]->height_ceiling - campaign->sector[i]->height_floor;
		campaign->sector[i]->texture_floor = wad->levels->sectors[i]->texture_floor;
		campaign->sector[i]->texture_ceiling = wad->levels->sectors[i]->texture_ceiling;
		campaign->sector[i]->light_level = wad->levels->sectors[i]->light_level;
		campaign->sector[i]->sector_tag = wad->levels->sectors[i]->sector_tag;
		
		// ft_printf("HEIGHT\nFLR: %hd\nCEIL: %hd\n", campaign->sector[i]->height_floor, campaign->sector[i]->height_ceiling);
		// ft_printf("TEXTURE\nFLR: %s\nCEIL: %s\n", campaign->sector[i]->texture_floor, campaign->sector[i]->texture_ceiling);
		// ft_printf("LIGHT: %hu\nTAG: %hu\n\n", campaign->sector[i]->light_level, campaign->sector[i]->sector_tag);

		i++;
	}	
}

void		print_sector_wall(t_campaign_sector *sector)
{
	size_t i;
	static size_t current = 0;

	i = 0;
	ft_printf("BELONG TO SECTOR: %d\n\n", current);
	while (i < sector->wall_amount)
	{
		ft_printf("X: %f, Y: %f\n", sector->wall[i]->vertex_begin->x, sector->wall[i]->vertex_begin->y);
		ft_printf("X: %f, Y: %f\n\n", sector->wall[i]->vertex_end->x, sector->wall[i]->vertex_end->y);
		// if (sector->wall[i]->sidedef_right) {
		// 	ft_printf("R_SIDE X: %d, Y: %d\n", sector->wall[i]->sidedef_right->offset_x, sector->wall[i]->sidedef_right->offset_y);
		// 	ft_printf("TEXTURE\nUP: %s\nMID: %s\nLOW: %s\n", sector->wall[i]->sidedef_right->texture_up, sector->wall[i]->sidedef_right->texture_mid, sector->wall[i]->sidedef_right->texture_low);
		// }
		// if (sector->wall[i]->sidedef_left) {
		// 	ft_printf("L_SIDE X: %d, Y: %d\n", sector->wall[i]->sidedef_left->offset_x, sector->wall[i]->sidedef_left->offset_y);
		// 	ft_printf("TEXTURE\nUP: %s\nMID: %s\nLOW: %s\n", sector->wall[i]->sidedef_left->texture_up, sector->wall[i]->sidedef_left->texture_mid, sector->wall[i]->sidedef_right->texture_low);
		// }
		i++;
	}
	ft_printf("\n");
	current++;
}
void		realloc_walls(t_campaign_sector *sector, t_campaign_wall *wall)
{
	size_t			i;
	t_campaign_wall	**new_walls;

	new_walls = (t_campaign_wall**)ft_memalloc(sizeof(t_campaign_wall*) * sector->wall_amount);
	if (new_walls == NULL)
		error_msg_errno("Failed to alloc level new walls");
	i = 0;
	while (i < sector->wall_amount - 1)
	{
		new_walls[i] = sector->wall[i];
		i++;
	}
	new_walls[i] = wall;
	free(sector->wall);
	sector->wall = new_walls;
}
void		apply_walls_to_sector(t_campaign *campaign)
{
	size_t	i;

	i = 0;
	while (i < campaign->wall_amount)
	{
		if (campaign->wall[i]->sidedef_left)
		{
			campaign->sector[campaign->wall[i]->sidedef_left->sector]->wall_amount++;
			realloc_walls(campaign->sector[campaign->wall[i]->sidedef_left->sector], campaign->wall[i]);
		}
		if (campaign->wall[i]->sidedef_right)
		{
			campaign->sector[campaign->wall[i]->sidedef_right->sector]->wall_amount++;
			realloc_walls(campaign->sector[campaign->wall[i]->sidedef_right->sector], campaign->wall[i]);
		}
		i++;
	}

	i = 0;
	while (i < campaign->sector_amount) {
		print_sector_wall(campaign->sector[i]);
		i++;
	}
}

void		set_player(t_campaign *campaign, t_wad *wad)
{
	size_t	i;

	i = 0;
	while (i < wad->levels->things_amount)
	{
		if (wad->levels->things[i]->types == 1)
		{
			campaign->player_start_pos.x = wad->levels->things[i]->x_pos;
			campaign->player_start_pos.y = wad->levels->things[i]->y_pos;
			campaign->player_start_angle = wad->levels->things[i]->angle;
			ft_printf("Pos X: %f\nPos Y: %f\nAngle: %hu\n",
				campaign->player_start_pos.x,
				campaign->player_start_pos.y,
				campaign->player_start_angle);
			return ;
		}
		i++;
	}
}

t_campaign	*convert_wad(t_wad *wad, t_game *game)
{
	t_campaign	*campaign;

	campaign = alloc_campaign();
	convert_vertex(campaign, wad);
	convert_sidedefs(campaign, wad);
	convert_walls(campaign, wad);
	convert_sectors(campaign, wad);
	apply_walls_to_sector(campaign);
	set_player(campaign, wad);
	convert_dssound(wad, game);
	return (campaign);
}
