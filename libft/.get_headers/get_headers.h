/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_headers.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 00:34:48 by pholster       #+#    #+#                */
/*   Updated: 2019/10/03 00:34:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_HEADERS_H
# define GET_HEADERS_H

typedef struct	s_header
{
	char			*name;
	struct s_header	*next;
}				t_header;

void			sort_headers(t_header **head);

#endif
