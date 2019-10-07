/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serializer.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 11:10:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 11:10:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <stdlib.h>
# include "libft/ft_bool.h"

t_bool			write_struct(char *loc,void *obj, size_t size);
unsigned char	*read_struct(char *loc);

#endif