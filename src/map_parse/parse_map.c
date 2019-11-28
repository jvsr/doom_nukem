/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:54:16 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/28 13:51:17 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "game.h"
#include "error.h"
#include "parse_map.h"

void	parse_map(char *const filename, t_game *game)
{
	t_wad		*wad;
	char *const extension = ft_strrchr(filename, '.');
	
	(void)game;
	if (extension == NULL)
		error_msg("Failed to parse map", 24, "invalid map extension");
	else if (ft_strequ_nocase(extension, ".wad"))
	{
		wad = parse_wad(filename);
		game->level = convert_wad(wad, game);
	}
}
