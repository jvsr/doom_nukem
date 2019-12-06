/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_thread.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 17:15:08 by pholster       #+#    #+#                */
/*   Updated: 2019/11/13 18:09:01 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_THREAD_H
# define SDL_THREAD_H

# include <stdarg.h>
# include <stdatomic.h>

# include <SDL2/SDL_thread.h>

# include "libft/ft_bool.h"

# define TRACK_TIME FALSE

typedef	enum	e_thread_state
{
	IDLE,
	ACTIVE,
	LOCKED
}				t_thread_state;

typedef struct	s_task
{
	void			(*f)();
	char			param_count;
	void			*params[4];
	struct s_task	*next;
}				t_task;

typedef struct	s_thread
{
	size_t			number;
	SDL_Thread		*thread;
	struct s_pool	*pool;
	t_task			*task;
	t_thread_state	state;
}				t_thread;

typedef struct	s_pool
{
	t_thread		**threads;
	t_task			*que;
	t_task			*que_last;
	atomic_char		state;
	t_bool			tracktime;
	t_bool			terminating;
	t_bool			suspended;
	size_t			size;
	t_bool			centralised;
	SDL_Thread		*manager;
}				t_pool;

/*
** ------------------------------"Face" Functions-------------------------------
*/

t_pool			*sdl_new_pool(size_t size,
										t_bool tracktime, t_bool centralised);
void			sdl_del_pool(t_pool **pool);
void			sdl_join_pool(t_pool const *pool);
t_bool			sdl_done_pool(t_pool const *pool);
t_bool			sdl_que_pool_back(t_pool *pool, void (*f)(),
					size_t param_count, ...);
t_bool			sdl_que_pool_front(t_pool *pool, void (*f)(),
					size_t param_count, ...);
SDL_Thread		*sdl_new_thread(char const *name, void (*f)(),
					size_t param_count, ...);

/*
** ----------------------------Management Functions-----------------------------
*/

int				sdl_manage_thread_central(void *param);
int				sdl_manage_thread_worker(void *param);
t_bool			sdl_que_pool(t_pool *pool, t_bool priority, t_task *task);

/*
** -------------------------------Task Functions--------------------------------
*/

t_task			*sdl_new_task(void (*f)(), size_t param_count, va_list params);
t_task			*sdl_get_task(t_pool *pool);
t_bool			sdl_run_task(t_task const *task);
void			sdl_complete_task(t_pool *pool, t_thread *self,
									float *waittime);

#endif
