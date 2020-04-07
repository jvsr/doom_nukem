/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_track_from_map.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 17:26:35 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 11:32:00 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"
#include "libft/ft_char.h"
#include "libft/ft_str.h"

#include "audio.h"
#include "error.h"

void	*get_track_from_map(t_hashmap *map, char *const name)
{
	char	*lower_name;
	void	*result;

	lower_name = ft_strmap(name, ft_tolower);
	if (lower_name == NULL)
		error_msg_errno(ft_strformat("Failed to allocate name of '%s'", name));
	result = ft_hashmapget_str(map, name);
	ft_strdel(&lower_name);
	return (result);
}
