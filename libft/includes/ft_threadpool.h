/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadpool.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:26:14 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:02:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADPOOL_H
# define FT_THREADPOOL_H

# include "ft_bool.h"
# include <string.h>
# include <stdarg.h>
# include <pthread.h>
# include <stdatomic.h>

typedef	enum	e_state
{
	IDLE,
	ACTIVE,
	LOCKED
}				t_state;

typedef struct	s_task
{
	void			(*fnc)();
	char			param_count;
	void			*params[4];
	struct s_task	*next;
}				t_task;

typedef struct	s_thread
{
	size_t			number;
	pthread_t		thread;
	struct s_pool	*pool;
	t_state			state;
}				t_thread;

typedef struct	s_pool
{
	t_thread		**threads;
	t_task			*que;
	t_task			*last;
	atomic_char		state;
	t_bool			tracktime;
	t_bool			terminating;
	t_bool			suspended;
	size_t			size;
}				t_pool;

/*
** "Face" Functions
*/

t_pool			*ft_poolnew(size_t size, t_bool tracktime);
void			ft_pooldel(t_pool **pool);
void			ft_pooljoin(t_pool *pool);
t_bool			ft_pooldone(t_pool *pool);
t_bool			ft_poolqueback(t_pool *pool, void (*f)(), size_t count, ...);
t_bool			ft_poolquefront(t_pool *pool, void (*f)(), size_t count, ...);
t_bool			ft_threadnew(pthread_t *thread, void (*f)(), size_t count, ...);

/*
** Management Functions
*/

void			*tp_threadmanager(void *param);
t_bool			tp_addtoque(t_pool *pool, t_bool priority, t_task *task);

/*
** Task Functions
*/

t_bool			tp_taskrunfnc(t_task *task);
t_task			*tp_tasksetinfo(t_task *task, void (*f)(), size_t count,
					va_list params);

#endif
