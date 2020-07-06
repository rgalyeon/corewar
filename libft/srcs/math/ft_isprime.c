/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:08:04 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/05 20:25:59 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_isprime(const int digit)
{
	int		i;
	int		tmp;

	if (digit <= 1)
		return (0);
	if (digit % 2 == 0)
		return (0);
	i = 3;
	tmp = digit / 2;
	while (i < tmp)
	{
		if (digit % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
