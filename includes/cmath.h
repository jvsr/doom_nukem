/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:11:10 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/22 13:11:10 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMATH_H
# define CMATH_H

# define PI 3.14159265359
# define PI_R 0.0174532925
# define PI_D 57.2957795131

typedef struct s_coord  t_coord;
typedef struct s_game   t_game;

typedef struct	s_line
{
	float		x;
	float		y;
	float		equals;
}				t_line;

t_coord		*get_collision(t_game *game,
                                    t_coord *a, t_coord *wall, t_coord *pos);
float		get_angle_from_vectors(t_coord *vec0, t_coord *vec1);
float		get_angle_from_vector(t_coord *vec);
t_coord		*get_vector_from_angle(float angle, t_coord *vec);
float		dot_vectors(t_coord *vec0, t_coord *vec1);
float		get_vector_magnitude(t_coord *vec);
t_coord		*get_vector_from_points(t_coord *pos0, t_coord *pos1, t_coord *vec);

#endif
