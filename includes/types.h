/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 14:53:49 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/14 17:09:46 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define ENEMY_MOVE_TEXTURE_COUNT 4
# define ENEMY_FORWARD_TEXTURE_COUNT ENEMY_MOVE_TEXTURE_COUNT
# define ENEMY_BACKWARD_TEXTURE_COUNT ENEMY_MOVE_TEXTURE_COUNT
# define ENEMY_LEFT_TEXTURE_COUNT ENEMY_MOVE_TEXTURE_COUNT
# define ENEMY_RIGHT_TEXTURE_COUNT ENEMY_MOVE_TEXTURE_COUNT
# define ENEMY_DEATH_TEXTURE_COUNT 2
# define ENEMY_ATTACK_TEXTURE_COUNT 1
# define ENEMY_TOTAL_TEXTURE_COUNT 19

typedef	unsigned char		t_uint8;
typedef	unsigned short		t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;

typedef enum				e_endian
{
	ENDIAN_BIG,
	ENDIAN_LITTLE
}							t_endian;

typedef enum				e_texture
{
	TEXTURE_INVALID = -1,
	TEXTURE_BRICK_WALL,
	TEXTURE_SKYBOX_DAY,
	TEXTURE_SKYBOX_DUSK,
	TEXTURE_CHAIR_BACK,
	TEXTURE_CHAIR_FRONT,
	TEXTURE_CHAIR_LEFT,
	TEXTURE_CHAIR_RIGHT,
	TEXTURE_BLOOD_SPLATTER,
	TEXTURE_QUARTZ,
	TEXTURE_HEALTH_PICKUP,
	TEXTURE_KEYS,
	TEXTURE_GLASS,
	TEXTURE_SPIKES,
	TEXTURE_ROCKS,
	TEXTURE_DOOR,
	TEXTURE_START,
	TEXTURE_END,
	TEXUTRE_AMMO,
	TEXTURE_SLOPE,
	TEXTURE_CPLUS,
	TEXTURE_CMINUS,
	TEXTURE_FPLUS,
	TEXTURE_FMINUS,
	TEXTURE_ENEMY0_F0,
	TEXTURE_ENEMY0_F1,
	TEXTURE_ENEMY0_F2,
	TEXTURE_ENEMY0_F3,
	TEXTURE_ENEMY0_B0,
	TEXTURE_ENEMY0_B1,
	TEXTURE_ENEMY0_B2,
	TEXTURE_ENEMY0_B3,
	TEXTURE_ENEMY0_L0,
	TEXTURE_ENEMY0_L1,
	TEXTURE_ENEMY0_L2,
	TEXTURE_ENEMY0_L3,
	TEXTURE_ENEMY0_R0,
	TEXTURE_ENEMY0_R1,
	TEXTURE_ENEMY0_R2,
	TEXTURE_ENEMY0_R3,
	TEXTURE_ENEMY0_D0,
	TEXTURE_ENEMY0_D1,
	TEXTURE_ENEMY0_A,
	TEXTURE_COUNT
}							t_texture;

typedef enum				e_enemystate
{
	ENEMY_IDLE,
	ENEMY_MOVING,
	ENEMY_ATTACK,
	ENEMY_DEAD
}							t_enemystate;

typedef enum				e_objanim
{
	OA_INVALID = -1,
	OA_CHAIR,
	OA_ENEMY,
	OA_COUNT
}							t_objanim;

typedef enum				e_obj
{
	O_INVALID = -1,
	O_CHAIR,
	O_ENEMY,
	O_SPIKE,
	O_KEY,
	O_HEALTH_PICKUP,
	O_START,
	O_END,
	O_AMMO,
	O_SKYBOX_DAY,
	O_SKYBOX_DUSK,
	O_SLOPE,
	O_CPLUS,
	O_CMINUS,
	O_FPLUS,
	O_FMINUS,
	O_COUNT
}							t_obj;

#endif
