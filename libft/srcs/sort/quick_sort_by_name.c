/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_by_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 23:31:45 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/05/18 20:14:22 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	quick_sort_by_name(char **data, int len, short int r)
{
	int	i;
	int	pvt;

	i = -1;
	pvt = 0;
	if (len <= 1)
		return ;
	--len;
	while (++i < len)
	{
		if (r * ft_strcmp(data[i], data[len]) < 0)
			ft_swap(&(data[i]), &(data[pvt++]));
	}
	ft_swap(&(data[pvt]), &(data[len]));
	quick_sort_by_name(data, pvt++, r);
	quick_sort_by_name(data + pvt, len + 1 - pvt, r);
}
