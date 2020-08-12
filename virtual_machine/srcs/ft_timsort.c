/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:39:26 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/08/12 17:04:37 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

/*
** Function get minimum size of subarray (minrun)
** @param length - length of array
** @return minrun
*/

static uint	get_minrun(uint length)
{
	uint	is_sign_bit;

	is_sign_bit = 0;
	while (length >= 64)
	{
		is_sign_bit |= length & 1u;
		length >>= 1u;
	}
	return (length + is_sign_bit);
}

/*
** Timsort for integer data type
** @param data - integer array
** @param length - length of integer array
*/

void 	ft_timsort(int *data, uint length)
{
	uint	minrun;

	if (length < 64)
		return (ft_insertion_sort(data, length));
	minrun = get_minrun(length);
}
