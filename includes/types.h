/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 14:53:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/28 16:36:22 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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
	TEXTURE_BRICK_WALL,
	TEXTURE_SKYBOX_DAY,
	TEXTURE_SKYBOX_DUSK,
	TEXTURE_LAMP,
	TEXTURE_CHAIR_BACK,
	TEXTURE_CHAIR_FRONT,
	TEXTURE_CHAIR_LEFT,
	TEXTURE_CHAIR_RIGHT,
	TEXTURE_BLOOD_SPLATTER,
	TEXTURE_QUARTZ,
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

#endif
