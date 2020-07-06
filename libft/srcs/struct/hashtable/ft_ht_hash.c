/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 08:58:57 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	ft_power(int a, int pow)
{
	if (0 == pow)
		return (1);
	if (pow % 2 == 1)
		return (a * ft_power(a, pow - 1));
	else
		return (ft_power(a * a, pow / 2));
}

int			ft_ht_hash(const char *str, const int prime, const int size)
{
	const int		len = (int)ft_strlen(str);
	int64_t			hash;
	int				i;

	i = -1;
	hash = 0;
	while (++i < len)
	{
		hash += ft_power(prime, len - (i + 1)) * str[i];
		hash = hash % size;
	}
	return ((int)hash);
}
