/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:18:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/28 15:39:03 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

typedef struct s_wad	t_wad;
typedef struct s_game	t_game;
typedef struct s_campaign	t_campaign;

void		parse_map(char *const filename, t_game *game);

t_wad		*parse_wad(char *const filename, const char *exec_path);
t_campaign	*convert_wad(t_wad *wad, t_game *game);

#endif
