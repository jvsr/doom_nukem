/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_add_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"

#include "cmath.h"
#include "rinfo.h"
#include "error.h"
#include "map_editor.h"

static t_bool	check_collision_valid(t_wall *wall, t_wall *other,
					t_coord *intersection)
{
	if (get_line_collision(&(t_bicoord){wall->corner_0, wall->corner_1},
		&(t_bicoord){other->corner_0, other->corner_1}, intersection) == NULL)
		return (TRUE);
	if (ft_memequ(&wall->corner_0, intersection, sizeof(t_coord)) == TRUE)
		return (TRUE);
	if (ft_memequ(&wall->corner_1, intersection, sizeof(t_coord)) == TRUE)
		return (TRUE);
	return (FALSE);
}

static t_bool	wall_is_bigger(t_wall *wall, t_wall *other)
{
	t_coord	other_vec;
	t_coord	wall_vec;
	float	other_mag;
	float	wall_mag;

	get_vector_from_points(&other->corner_0, &other->corner_1, &other_vec);
	get_vector_from_points(&wall->corner_0, &wall->corner_1, &wall_vec);
	other_mag = get_vector_magnitude(&other_vec);
	wall_mag = get_vector_magnitude(&wall_vec);
	if (wall_mag > other_mag)
		return (TRUE);
	return (FALSE);
}

static t_bool	check_coincident_valid(t_wall *wall, t_wall *other)
{
	float		wall_angle;
	float		other_angle;
	t_bicoord	other_line;
	t_coord		d;

	if (wall_is_bigger(wall, other) == TRUE)
		return (check_coincident_valid(other, wall));
	wall_angle = get_angle_between_points(&wall->corner_0, &wall->corner_1);
	other_angle = get_angle_between_points(&other->corner_0, &other->corner_1);
	if (other_angle != wall_angle && wrap_angle(other_angle + 180) != wall_angle)
		return (TRUE);
	get_vector_from_points(&other->corner_0, &other->corner_1, &d);
	if (fabs(d.x) <= EDITOR_GRID_STEP && fabs(d.y) <= EDITOR_GRID_STEP)
		return (TRUE);
	d = (t_coord){EDITOR_GRID_STEP * clamp_float(d.x, -1, 1),
		EDITOR_GRID_STEP * clamp_float(d.y, -1, 1)};
	other_line = (t_bicoord){
		(t_coord){other->corner_0.x + d.x, other->corner_0.y + d.y},
		(t_coord){other->corner_1.x - d.x, other->corner_1.y - d.y}};
	if (circle_collision(&other_line, &wall->corner_0, 1) == TRUE ||
		circle_collision(&other_line, &wall->corner_1, 1) == TRUE)
		return (FALSE);
	return (TRUE);
}

static void		add_to_back(t_list **head, t_list *new)
{
	t_wall	*new_wall;
	t_wall	*wall;
	t_list	*lst;
	t_bool	valid;
	t_coord	intersection;

	lst = *head;
	valid = TRUE;
	new_wall = (t_wall*)new->content;
	while (lst != NULL)
	{
		wall = (t_wall*)lst->content;
		valid = check_collision_valid(new_wall, wall, &intersection);
		if (valid == TRUE)
			valid = check_coincident_valid(new_wall, wall);
		if (valid == FALSE || lst->next == NULL)
			break ;
		lst = lst->next;
	}
	if (valid == FALSE)
		ft_lstdel(&new, ft_lstdelmem);
	else if (lst == NULL)
		*head = new;
	else
		lst->next = new;
}

void			map_editor_add_wall(t_editor_map *editor_map, t_wall *wall)
{
	t_list	*new;

	new = ft_lstnew((void*)wall, sizeof(t_wall));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor wall");
	add_to_back(&editor_map->walls, new);
}
