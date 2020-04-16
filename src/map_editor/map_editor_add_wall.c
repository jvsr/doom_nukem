/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_add_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/13 14:00:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"

#include "cmath.h"
#include "error.h"
#include "map_editor.h"

static void		split_wall_intersection(t_editor_map *editor_map,
					t_editor_wall *wall, t_editor_wall *other)
{
	t_coord	intersection;
	t_coord	corner_0;
	t_coord	corner_1;

	if (other == NULL)
		return ;
	get_line_collision(&(t_bicoord){wall->corner_0, wall->corner_1},
		&(t_bicoord){other->corner_0, other->corner_1}, &intersection);
	if (ft_memequ(&other->corner_0, &intersection, sizeof(t_coord)) == TRUE ||
		ft_memequ(&other->corner_1, &intersection, sizeof(t_coord)) == TRUE)
		return ;
	corner_0 = other->corner_0;
	corner_1 = other->corner_1;
	map_editor_del_wall(editor_map, other);
	map_editor_new_wall(editor_map, corner_0, intersection);
	map_editor_new_wall(editor_map, intersection, corner_1);
}

static t_bool	check_collision_valid(t_editor_wall *wall, t_editor_wall *other,
					t_editor_wall *intersect_walls[2])
{
	t_coord	intersection;

	if ((ft_memequ(&wall->corner_0, &other->corner_0, sizeof(t_coord)) ||
		ft_memequ(&wall->corner_0, &other->corner_1, sizeof(t_coord))) &&
		(ft_memequ(&wall->corner_1, &other->corner_0, sizeof(t_coord)) ||
		ft_memequ(&wall->corner_1, &other->corner_1, sizeof(t_coord))))
		return (FALSE);
	if (get_line_collision(&(t_bicoord){wall->corner_0, wall->corner_1},
		&(t_bicoord){other->corner_0, other->corner_1}, &intersection) == NULL)
		return (TRUE);
	if (ft_memequ(&wall->corner_0, &intersection, sizeof(t_coord)) == FALSE &&
		ft_memequ(&wall->corner_1, &intersection, sizeof(t_coord)) == FALSE)
		return (FALSE);
	if (intersect_walls[0] == NULL)
		intersect_walls[0] = other;
	else
		intersect_walls[1] = other;
	return (TRUE);
}

static t_bool	check_coincident_valid(t_editor_wall *wall,
					t_editor_wall *other)
{
	float		wall_angle;
	float		other_angle;
	t_bicoord	other_line;
	t_coord		d;

	if (map_editor_wall_is_bigger(wall, other) == TRUE)
		return (check_coincident_valid(other, wall));
	wall_angle = get_angle_between_points(&wall->corner_0, &wall->corner_1);
	other_angle = get_angle_between_points(&other->corner_0, &other->corner_1);
	if (other_angle != wall_angle &&
		wrap_angle(other_angle + 180) != wall_angle)
		return (TRUE);
	get_vector_from_points(&other->corner_0, &other->corner_1, &d);
	d = (t_coord){
		(EDITOR_GRID_STEP / 2) * clamp_float(d.x, -1, 1),
		(EDITOR_GRID_STEP / 2) * clamp_float(d.y, -1, 1)};
	other_line = (t_bicoord){
		(t_coord){other->corner_0.x + d.x, other->corner_0.y + d.y},
		(t_coord){other->corner_1.x - d.x, other->corner_1.y - d.y}};
	if (circle_collision(&other_line, &wall->corner_0, 1) == TRUE ||
		circle_collision(&other_line, &wall->corner_1, 1) == TRUE)
		return (FALSE);
	return (TRUE);
}

static t_bool	add_to_back(t_editor_map *editor_map, t_list *new)
{
	t_editor_wall	*new_wall;
	t_list			*lst;
	t_editor_wall	*intersect_walls[2];

	lst = editor_map->walls;
	new_wall = (t_editor_wall*)new->content;
	ft_bzero(&intersect_walls, sizeof(t_editor_wall*) * 2);
	while (lst != NULL)
	{
		if (!check_collision_valid(new_wall, lst->content, intersect_walls) ||
			!check_coincident_valid(new_wall, lst->content))
			return (FALSE);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	if (lst == NULL)
		editor_map->walls = new;
	else
		lst->next = new;
	split_wall_intersection(editor_map, new_wall, intersect_walls[0]);
	split_wall_intersection(editor_map, new_wall, intersect_walls[1]);
	return (TRUE);
}

t_bool			map_editor_add_wall(t_editor_map *editor_map,
					t_editor_wall *wall)
{
	t_list	*new;

	new = ft_lstnew((void*)wall, sizeof(t_editor_wall));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor wall");
	if (add_to_back(editor_map, new) == FALSE)
	{
		ft_lstdel(&new, ft_lstdelmem);
		return (FALSE);
	}
	return (TRUE);
}
