/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setting.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 19:19:06 by pholster      #+#    #+#                 */
/*   Updated: 2019/10/16 19:19:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_keycode.h>

# include "types.h"
# include "libft/ft_bool.h"

# define MAX_FOV 75
# define MIN_FOV 45
# define FOV_STEP 5

# define SETTINGS_PATH "resources/data/settings/"

typedef enum	e_resolution_type
{
	windowed,
	fullscreen,
	borderless
}				t_resolution_type;

typedef struct	s_control
{
	SDL_Keycode	shoot;
	SDL_Keycode	interact;
	SDL_Keycode	jump;
	SDL_Keycode	crouch;
	SDL_Keycode	forward;
	SDL_Keycode	backward;
	SDL_Keycode	left;
	SDL_Keycode	right;
}				t_control;

typedef struct	s_setting
{
	float				sensitivity;
	float				music_volume;
	float				sound_volume;
	float				vfov;
	t_uint16			fov;
	SDL_Point			resolution;
	t_resolution_type	resolution_type;
	t_control			controls;
	t_bool				changed;
	t_bool				confirm;
}				t_setting;

#endif
