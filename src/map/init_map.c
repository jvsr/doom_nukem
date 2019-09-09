/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:25:52 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 18:58:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "libft/ft_memory.h"

#include "map.h"
#include "game.h"
#include "coord.h"
#include "error.h"
#include "player.h"

static int	open_map(const char *name)
{
	int fd;
	
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg(strerror(errno), errno);
	return (fd);
}

static void	map_player(int fd, t_player *player)
{
	ssize_t	res;
	const ssize_t size = sizeof(t_vec) + sizeof(uint32_t) + sizeof(uint8_t);

	res = read(fd, player, size);
	if (res < size)
		error_msg(strerror(errno), errno);
}

static void	map_sectors(int fd, t_map *map)
{
	ssize_t	res;
	const ssize_t size = sizeof(uint8_t);

	res = read(fd, &(map->num_sector), size);
	if (res < size)
		error_msg(strerror(errno), errno);
	map->all_sectors = (t_sector*)ft_memalloc(sizeof(t_sector) * map->num_sector);
	if (map->all_sectors == NULL)
		error_msg(strerror(errno), errno);
}

void		init_map_player(const char *name, t_game *game)
{
	int fd;

	fd = open_map(name);
	game->map = (t_map*)ft_memalloc(sizeof(t_map));
	game->player = (t_player*)ft_memalloc(sizeof(t_player));
	if (game->map == NULL || game->player == NULL)
		error_msg(strerror(errno), errno);
	map_player(fd, game->player);
	map_sectors(fd, game->map);
}
