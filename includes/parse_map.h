/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:18:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/25 15:35:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

typedef struct s_wad	t_wad;


void	parse_map(char *const filename);

t_wad	*parse_wad(char *const filename);

#endif
