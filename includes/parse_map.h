/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:18:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/25 17:32:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

typedef struct s_wad	t_wad;
typedef struct s_game	t_game;


void	parse_map(char *const filename, t_game *game);

t_wad	*parse_wad(char *const filename);

#endif
