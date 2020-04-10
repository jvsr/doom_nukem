/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:11:10 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 18:00:19 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMATH_H
# define CMATH_H

# define PI 3.14159265359
# define PI_R 0.0174532925
# define PI_D 57.2957795131

# include "libft/ft_bool.h"

typedef struct s_coord		t_coord;
typedef struct s_bicoord	t_bicoord;
typedef struct s_game		t_game;
typedef struct s_setting	t_setting;

t_coord		*get_collision(t_coord *start,
				t_coord *a, t_coord *wall, t_coord *pos);\
t_coord		*get_line_collision(t_bicoord *line1, t_bicoord *line2,
				t_coord *result);
t_bool		line_collision(t_bicoord *line1, t_bicoord *line2);
t_bool		circle_collision(t_bicoord *line, t_coord *circle_mid,
				float radius);
float		get_angle_from_vectors(t_coord *vec0, t_coord *vec1);
float		get_angle_from_vector(t_coord *vec);
t_coord		*get_vector_from_angle(float angle, t_coord *vec);
float		dot_vectors(t_coord *vec0, t_coord *vec1);
float		get_vector_magnitude(t_coord *vec);
t_coord		*get_vector_from_points(t_coord *pos0, t_coord *pos1, t_coord *vec);
float		get_distance(t_coord *pos0, t_coord *pos1);
float		calc_vfov(float fov, float width, float height);
float		mod_float(float f0, float max);
float		clamp_float(float f0, float min, float max);
float		wrap_float(float f0, float min, float max);
t_coord		get_perps(float angle);
float		wrap_angle(float angle);
t_coord		intersect3(t_coord c0, t_coord c1, t_coord c2, t_coord c3);
t_bool		is_between_fov(float a, float start, float end);
float		get_angle_between_points(t_coord *a, t_coord *b);
float		calc_fov(float a, float b);
float		get_angle_between_pointsv(t_coord *pos0, t_coord *pos1);
float		lerp(float a, float b, float t);
float		lerp_max(float a, float b, float t, float max);
t_coord		get_perp(t_coord *vec);
t_coord		*normalize_vector(t_coord *vec);
t_bool		is_between(float a, float x, float y);
int			get_side_vec(t_coord *v0, t_coord *v1, int is_clockwise);
t_bool		is_between_or_equal(float a, float x, float y);
t_bool		coordequ(t_coord *v0, t_coord *v1);

#endif
