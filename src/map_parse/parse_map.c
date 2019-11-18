/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 11:54:16 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/18 12:19:13 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "error.h"
#include "parse_map.h"

#include <stdio.h> //
void	parse_map(char *const filename)
{
	char *const extension = ft_strrchr(filename, '.');

	if (extension == NULL)
		error_msg("Failed to parse map", 24, "invalid map extension");
	else if (ft_strequ_nocase(extension, ".wad"))
		parse_wad(filename);
}
