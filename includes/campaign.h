/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   campaign.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 15:16:00 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/29 19:25:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMPAIGN_H
# define CAMPAIGN_H

# include "coord.h"

typedef struct			s_campaign_sidedef
{
	short				offset_x;
	short				offset_y;
	char				*texture_up;
	char				*texture_low;
	char				*texture_mid;
	unsigned short		sector;
}						t_campaign_sidedef;

typedef struct			s_campaign_wall
{
	t_coord				*vertex_begin;
	t_coord				*vertex_end;
	t_campaign_sidedef	*sidedef_right;
	t_campaign_sidedef	*sidedef_left;
	unsigned short		sector_tag;
}						t_campaign_wall;

typedef struct			s_campaign_sector
{
	short				height_floor;
	short				height_ceiling;
	char				*texture_floor;
	char				*texture_ceiling;
	short				light_level;
	size_t				wall_amount;
	t_campaign_wall		**wall;
	unsigned short		sector_tag;
}						t_campaign_sector;

typedef struct	s_campaign
{
	t_coord				*vertex;
	size_t				wall_amount;
	t_campaign_wall		**wall;
	size_t				sidedef_amount;
	t_campaign_sidedef	**sidedef;
	size_t				sector_amount;
	t_campaign_sector	**sector;
}				t_campaign;

#endif
