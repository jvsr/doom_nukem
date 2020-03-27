/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:16:11 by jvisser        #+#    #+#                */
/*   Updated: 2020/03/26 11:23:58 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "types.h"
# include "coord.h"
# include "libft/ft_bool.h"

# define PLAYER_HEIGHT 9.0
# define PLAYER_CROUCH 5.0
# define PLAYER_JUMP 20.0
# define PLAYER_JUMP_FRAMES 20
# define PLAYER_UPDOWN_MIN -0.45
# define PLAYER_UPDOWN_MAX 0.60
# define PLAYER_MOVE_SPEED 0.5
# define BASE_FRAME_TIME 25
# define PLAYER_RUN_SPEED 0.7
# define PLAYER_CLIMB 5.0
# define PLAYER_CROUCH_SPEED 0.2
# define PLAYER_H_SENSE 0.12
# define PLAYER_V_SENSE 0.002
# define PLAYER_MOVE_BASE_FPS 40
# define PLAYER_INIT_DROP_SPEED 2.5
# define PLAYER_TERM_V 30

# define PLAYER_INIT_JUMP_HEIGHT 30
# define PLAYER_JUMP_TIME 250
# define PLAYER_MAX_HEALTH 50
# define PLAYER_FLY_SPEED 2000

# define DAMAGE_REPEAT_SPEED 750

typedef struct s_game		t_game;
typedef struct s_hashmap	t_hashmap;
typedef struct s_map		t_map;
typedef struct s_object		t_object;
typedef struct s_sector		t_sector;

typedef struct	s_mag
{
	double cos;
	double sin;
}				t_mag;

typedef	struct	s_player
{
	t_uint32	health;
	t_uint32	ammo;
	t_uint16	*fov;
	float		angle;
	t_mag		mag;
	t_coord		forward;
	t_coord		pos;
	t_uint32	cur_sector;
	float		height;
	float		player_height;
	float		heightoffset;
	float		updown;
	int			screen_updown;
	t_bool		is_flying;
	t_bool		is_dead;
	t_uint32	keys;
}				t_player;

t_bool			player_move(t_game *game);
t_bool			player_col(t_game *game, float xspeed, float yspeed);
void			health_pickup(t_game *game,
					t_sector *sec, t_object *obj, t_player *player);
void			key_pickup(t_game *game,
					t_sector *sec, t_object *obj, t_player *player);
void			spike_damage(t_game *game,
							t_sector *sec, t_object *obj, t_player *player);
t_bool			move_forward(t_player *player, float speed,
								float *xspeed, float *yspeed);
t_bool			move_backward(t_player *player, float speed,
								float *xspeed, float *yspeed);
t_bool			move_left(t_player *player, float speed,
								float *xspeed, float *yspeed);
t_bool			move_right(t_player *player, float speed,
								float *xspeed, float *yspeed);
t_bool			move_jump(t_game *game, t_player *player, t_bool *jump);
t_bool			move_down(t_game *game, t_player *player, t_bool *jump);
t_bool			fly_up(t_game *game, t_player *player, t_bool *jump);
t_bool			fly_down(t_game *game, t_player *player, t_bool *jump);
void			damage_player(t_game *game, t_player *player, t_uint32 damage);
void			player_died(t_game *game);
float			player_slope(t_player *pyr, t_sector *sec, t_coord *pos);

#endif
