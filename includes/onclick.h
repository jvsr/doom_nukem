/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onclick.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:08:10 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/15 17:08:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONCLICK_H
# define ONCLICK_H

typedef struct s_game		t_game;
typedef struct s_transform	t_transform;

void	mainmenu_options(t_game *game, t_transform *gui);
void	mainmenu_quit(t_game *game, t_transform *gui);

void	options_return(t_game *game, t_transform *gui);

#endif
