/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vec_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:10:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/07/25 15:13:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_vec	*ft_int_vec_push(t_vec **vec, int c)
{
	void	*tmp;

	if (!(*vec))
		return (NULL);
	tmp = (*vec)->data;
	if ((*vec)->total >= (*vec)->capacity)
	{
		if (!((*vec)->data = ft_memalloc((*vec)->capacity * sizeof(int) * 2)))
		{
			free(tmp);
			free(*vec);
			return (NULL);
		}
		(*vec)->capacity *= 2;
		ft_memcpy((*vec)->data, tmp, (*vec)->total * sizeof(int));
		free(tmp);
		(((int *)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	else
	{
		(((int *)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	return (*vec);
}

