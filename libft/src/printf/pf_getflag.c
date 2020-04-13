/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getflag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:28:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_char.h"

static void	handleconflicts(t_info *info)
{
	info->flag[4] = (info->flag[3] == FALSE && info->flag[4]);
	info->flag[1] = (info->flag[2] == FALSE && info->flag[1]);
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
			info->flag[0] = TRUE;
		else if (str[i] == '0')
			info->flag[1] = TRUE;
		else if (str[i] == '-')
			info->flag[2] = TRUE;
		else if (str[i] == '+')
			info->flag[3] = TRUE;
		else if (str[i] == ' ')
			info->flag[4] = TRUE;
		else if (str[i] == '\'')
			info->flag[5] = TRUE;
		spacer = (str[i] != 0);
		i++;
	}
	handleconflicts(info);
	return (i);
}
