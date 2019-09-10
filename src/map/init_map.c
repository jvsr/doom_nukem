/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:25:52 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 14:33:57 by jvisser       ########   odam.nl         */
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
	
	fd = open(name, O_RDWR);
	if (fd < 0)
		error_msg(strerror(errno), errno);
	return (fd);
}

#include <stdio.h>

static void	map_player(int fd, t_player *player)
{
	ssize_t	res;
	const ssize_t size = sizeof(t_vec) + sizeof(uint32_t) + sizeof(uint8_t);

	res = read(fd, player, size);
    printf("Size read: %zd - %zd:\n\t%f\n\t%f\n\t%f\n\t%d\n\t%d\n", res, size,
        player->pos.x,
        player->pos.y,
        player->pos.z,
        player->ang,
        player->cur_sector
    );
	if (res < size)
		error_msg(strerror(errno), errno);
}

static void map_num(int fd, void *loc, size_t size)
{
    ssize_t res;

    res = read(fd, loc, size);
    if (res < (ssize_t)size)
		error_msg(strerror(errno), errno);
}

static void *map_struct(int fd, size_t size, size_t size_struct)
{
    ssize_t  res;
    void    *loc;

	loc = ft_memalloc(size_struct * size);
	if (loc == NULL)
		error_msg(strerror(errno), errno);
    res = read(fd, loc, size_struct * size);
    if (res < (ssize_t)(size_struct * size))
		error_msg(strerror(errno), errno);
    return (loc);
}

void		init_map_player(const char *name, t_game *game)
{
	int fd;

	fd = open_map(name);

/*
** ! Remove
*/
    const int ang = 32490;
    const int cursec = 1;
    const int numsec = 0;
    const int numwll = 0;
    const int numobj = 0;
    write(fd, &((t_vec){3, 2, 1}), sizeof(t_vec));
    write(fd, &ang, sizeof(uint32_t));
    write(fd, &cursec, sizeof(uint8_t));
    write(fd, &numsec, sizeof(uint8_t));
    write(fd, &numwll, sizeof(uint16_t));
    write(fd, &numobj, sizeof(uint16_t));
    close(fd);
	fd = open_map(name);
/*
** ! Remove
*/

	game->map = (t_map*)ft_memalloc(sizeof(t_map));
	game->player = (t_player*)ft_memalloc(sizeof(t_player));
	if (game->map == NULL || game->player == NULL)
		error_msg(strerror(errno), errno);
	map_player(fd, game->player);
    map_num(fd, &game->map->num_sector, sizeof(uint8_t));
    game->map->all_sectors = map_struct(fd, game->map->num_sector, sizeof(t_sector));
    map_num(fd, &game->map->num_wall, sizeof(uint16_t));
    game->map->all_walls = map_struct(fd, game->map->num_wall, sizeof(t_sector));
    map_num(fd, &game->map->num_object, sizeof(uint16_t));
    game->map->all_objects = map_struct(fd, game->map->num_object, sizeof(t_sector));
}
