/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_thread.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 17:15:08 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/19 20:53:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_THREAD_H
# define SDL_THREAD_H

# include <unistd.h>
# include <SDL2/SDL_thread.h>

# include "libft/ft_types.h"
# include "libft/ft_bool.h"

# define MAX_TTASK_PARAMS	4

typedef struct s_ttask		t_ttask;
typedef struct s_tjob		t_tjob;
typedef	struct s_tthread	t_tthread;
typedef struct s_tpool		t_tpool;

typedef	enum		e_tflags
{
	TFLAG_POOL_TERMINATE = 0b1,
	TFLAG_POOL_ALLOC_ON_EXEC = 0b10,
	TFLAG_TASK_NO_DELETE = 0b100,
	TFLAG_TASK_HIGH_PRIOR = 0b1000,
}					t_tflags;

typedef union		u_treturn
{
	t_int64			*i_ptr;
	double			*f_ptr;
	t_uint64		*u_ptr;
	t_bool			*b_ptr;
	char			*c_ptr;
	void			*v_ptr;
}					t_treturn;

struct				s_ttask
{
	void			*(*f)();
	void			*params[MAX_TTASK_PARAMS];
	size_t			param_count;
	t_uint64		flags;
	t_treturn		ret;
	t_bool			completed;
	SDL_cond		*cond_completed;
	SDL_mutex		*lock;
	t_ttask			*next;
};

struct				s_tjob
{
	t_ttask			*task;
	t_tjob			*next;
};

typedef struct		s_tqueue
{
	t_tjob			*first;
	t_tjob			*last;
	size_t			size;
	SDL_cond		*cond_empty;
	SDL_cond		*cond_not_empty;
	SDL_mutex		*lock;
}					t_tqueue;

struct				s_tthread
{
	SDL_Thread		*id;
	size_t			num;
	t_bool			running_task;
	t_ttask			*task;
	t_tpool			*pool;
};

struct				s_tpool
{
	size_t			size;
	t_tthread		*manager;
	t_tthread		**threads;
	t_tqueue		*tasks;
	t_bool			alloced;
	t_uint64		flags;
};

/*
**	--- Alloc functions ---
*/
t_tjob				*sdl_new_tjob(t_ttask *task);
t_tpool				*sdl_new_tpool(size_t size, t_uint64 flags);
t_tthread			*sdl_new_tthread(t_tpool *pool, size_t num,
									int (*f)(void *));
t_tqueue			*sdl_new_tqueue(void);
t_ttask				*sdl_new_ttask(void *(*fnc)(), t_uint64 flags,
								size_t param_count, ...);

void				sdl_alloc_tpool_tthreads(t_tpool **pool);

/*
**	--- Delete functions ---
*/
void				*sdl_del_tjob(t_tjob **job, t_bool delete_task);
void				*sdl_del_tpool(t_tpool **pool);
void				*sdl_del_tthread(t_tthread **thread);
void				*sdl_del_tqueue(t_tqueue **queue);
void				*sdl_del_ttask(t_ttask **task);
void				*sdl_del_ttask_all(t_ttask **task);

/*
**	--- Sync functions ---
*/
void				sdl_join_tpool(t_tpool *pool);
void				sdl_join_ttask(t_ttask *task);
void				sdl_join_ttask_all(t_ttask *task);

/*
**	--- Task functions ---
*/
void				sdl_run_ttask(t_ttask *task);
void				sdl_get_ttask(t_tthread *thread);
void				sdl_complete_ttask(t_ttask *task);
t_ttask				*sdl_add_tpool_ttask(t_tpool *pool, t_ttask *task);
t_ttask				*sdl_add_tqueue_ttask(t_tqueue *queue, t_ttask *task);

/*
**	--- Thread logic functions ---
*/
int					sdl_worker_tthread(void *param);

/*
**	--- Misc functions ---
*/
ssize_t				sdl_get_core_count(void);
t_ttask				*sdl_run_thread(const char *name, t_ttask *task);

#endif
