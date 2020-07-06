/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:10:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/04/16 05:39:41 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_vec	*ft_ptr_vec_push(t_vec **vec, void *c)
{
	void	*tmp;

	if (!(*vec))
		return (NULL);
	tmp = (*vec)->data;
	if ((*vec)->total >= (*vec)->capacity)
	{
		if (!((*vec)->data =
						ft_memalloc(sizeof(void *) * ((*vec)->capacity * 2))))
		{
			free(tmp);
			free(*vec);
			return (NULL);
		}
		(*vec)->capacity *= 2;
		ft_memcpy((*vec)->data, tmp, sizeof(void *) * (*vec)->total);
		free(tmp);
		(((void **)(*vec)->data))[(*vec)->total++] = c;
	}
	else
		(((void **)(*vec)->data))[(*vec)->total++] = c;
	return (*vec);
}
