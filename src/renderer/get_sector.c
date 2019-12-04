/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_sector.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:40:11 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/04 14:40:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "campaign.h"

t_campaign_sector	*get_sector(unsigned short tag, t_campaign_sector **sectors)
{
	int i;

	i = 0;
	while (sectors[i])
	{
		if (sectors[i]->sector_tag == tag)
			return (sectors[i]);
		i++;
	}
	return (NULL);
}
