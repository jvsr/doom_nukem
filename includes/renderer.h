/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:59:14 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/28 14:53:01 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "coord.h"
#include "campaign.h"
# include <SDL2/SDL_surface.h>

# define RENDER_THREAD_COUNT 4

typedef struct	s_list		t_list;
typedef struct	s_game		t_game;
typedef enum	e_texture	t_texture;

typedef struct	s_renderinfo
{
	float		ratio;
	t_coord		b_vec;
	int			*mask;
	SDL_Surface	*dst;
}				t_renderinfo;

void				render_3d(t_game *game, SDL_Surface *dst);
SDL_Surface			*get_texture(t_game *game, t_texture texture);
void				load_textures(t_game *game);

#endif
