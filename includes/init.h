/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:39:20 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 13:47:30 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define INIT_WIDTH	1920
# define INIT_HEIGHT 1080
# define INIT_KEYMAP_SIZE 20
# define INIT_KEYMAP_ALGO ft_hashdjb2a
# define INIT_THREADPOOL_SIZE_FALLBACK 4

typedef struct s_game	t_game;

t_game	*init_prerequisites(char **argv, char **envp);
void	*init_function(t_game *game);
void	init_gui(t_game *game);
void	init_audio(t_game *game);
void	init_keymap(t_game *game);
void	init_settings(t_game *game);
void	init_eventstate(t_game *game);
void	*init_main_menu(t_game *game);
void	init_window_surface(t_game *game);
void	unpack_resources(t_game *game);

#endif
