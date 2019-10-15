/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 14:53:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 14:55:04 by ehollidg      ########   odam.nl         */
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

#endif
