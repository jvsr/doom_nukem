/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:39:20 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 15:40:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define INIT_WIDTH 1080
# define INIT_HEIGHT 720

typedef struct s_game	t_game;

t_game	*init(void);
void	init_gui(t_game *game);

#endif
