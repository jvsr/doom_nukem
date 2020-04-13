/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean_funcs2.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 14:19:50 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 14:37:46 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_list.h"
#include "map_editor.h"

t_bool		get_closest(float prev, float cur)
{
	if (prev < 0 && cur > 0)
		return (TRUE);
	else if (prev < 0 && cur < 0 && cur > prev)
		return (TRUE);
	else if (prev > 0 && cur > 0 && cur < prev)
		return (TRUE);
	return (FALSE);
}

t_list		*get_correct_sectors(t_editor_wall *con, t_list *walls)
{
	t_list	*secs;

	secs = NULL;
	if (con->sectors[0] != NULL && con->sectors[1] != NULL)
		return (NULL);
	if (con->sectors[0] == NULL)
		ft_lstaddbck(&secs, ft_lstnew(get_room(ft_lstnew(con,
			sizeof(t_editor_wall)), walls, con, FALSE), sizeof(t_list)));
	if (con->sectors[1] == NULL)
		ft_lstaddbck(&secs, ft_lstnew(get_room(ft_lstnew(con,
			sizeof(t_editor_wall)), walls, con, TRUE), sizeof(t_list)));
	return (secs);
}
