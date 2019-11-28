/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:59:14 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/28 16:18:40 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "coord.h"

# define RENDER_THREAD_COUNT 4

typedef struct s_level	t_level;
typedef struct s_sector	t_sector;
typedef struct s_wall	t_wall;
typedef struct s_list	t_list;

void			render_3d(t_game *game, t_level *level);
SDL_Surface		*get_texture(t_game *game, t_texture texture);
void 			load_textures(t_game *game);
void			render_rooms(t_game *game, t_level *level);
t_wall			**get_walls_from_sector(t_sector *sector, t_level *level);
t_list			*get_bunches(t_game *game, t_level *level);
t_wall          *get_closest(t_list *walls, t_vec *pos);
void		   	render_part(t_game *game, t_coord range,
                                                t_list *walls, int *mask);
void		    add_wall_to_out(t_list **out_walls,
									t_wall *wall, t_game *game, float parts);

#endif
