/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   effect_all_sounds.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 14:34:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/26 14:34:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	effect_all_sounds(int (*func)(int))
{
	int	index;

	index = 0;
	while (index < 16)
	{
		func(index);
		index++;
	}
}
