/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_track_to_map.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 17:26:35 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 11:30:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"
#include "libft/ft_char.h"
#include "libft/ft_str.h"

#include "audio.h"
#include "error.h"

void	add_track_to_map(t_hashmap *map, void *track, char *const name)
{
	char	*lower_name;

	lower_name = ft_strmap(name, ft_tolower);
	if (lower_name == NULL)
		error_msg_errno(ft_strformat("Failed to allocate name of '%s'", name));
	if (ft_hashmapadd_str(map, name, track) == FALSE)
		error_msg_errno(ft_strformat("Failed to add '%s' to track map", name));
	ft_strdel(&lower_name);
}
