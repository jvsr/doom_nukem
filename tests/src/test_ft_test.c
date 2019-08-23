/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 15:12:17 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 11:43:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <criterion/criterion.h>

Test(test, null) {
	cr_assert(0 == NULL);
}
