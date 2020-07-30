/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:33:32 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:29:40 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_vec	*ft_int_vec_init(size_t capacity)
{
	t_vec *vec;

	if (!capacity || !(vec = (t_vec *)ft_memalloc(sizeof(t_vec))))
		return (NULL);
	if (!(vec->data = ft_memalloc(capacity * sizeof(int))))
	{
		free(vec);
		return (NULL);
	}
	vec->capacity = capacity;
	vec->total = 0;
	vec->offset = 0;
	return (vec);
}


