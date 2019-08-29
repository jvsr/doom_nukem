/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getflag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:28:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_character.h"

static void	handleconflicts(t_info *info)
{
	PF_FLAG_SPACE = (PF_FLAG_PLUS == FALSE && PF_FLAG_SPACE);
	PF_FLAG_ZERO = (PF_FLAG_MIN == FALSE && PF_FLAG_ZERO);
}

size_t		pf_getflag(t_info *info, const char *str)
{
	size_t	i;
	t_bool	spacer;

	i = 0;
	spacer = 0;
	while (i == 0 || ft_chrin(PF_A_FLAG, str[i]) ||
		(ft_chrin(PF_A_SPACER, str[i]) && spacer == FALSE))
	{
		if (str[i] == '#')
			PF_FLAG_HASH = TRUE;
		else if (str[i] == '0')
			PF_FLAG_ZERO = TRUE;
		else if (str[i] == '-')
			PF_FLAG_MIN = TRUE;
		else if (str[i] == '+')
			PF_FLAG_PLUS = TRUE;
		else if (str[i] == ' ')
			PF_FLAG_SPACE = TRUE;
		else if (str[i] == '\'')
			PF_FLAG_APOST = TRUE;
		spacer = (str[i] != 0);
		i++;
	}
	handleconflicts(info);
	return (i);
}
