/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:39:20 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/06 16:12:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define INIT_WIDTH	1080
# define INIT_HEIGHT 720
# define INIT_KEYMAP_SIZE 20
# define INIT_KEYMAP_ALGO ft_hashdjb2a

typedef struct s_game	t_game;

t_game	*init(void);
void	init_keymap(t_game *game);

#endif
