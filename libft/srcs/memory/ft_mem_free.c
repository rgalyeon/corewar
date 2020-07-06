/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:51:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/02/23 15:00:41 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_mem_free(void *ptr)
{
	t_vec	*vec;
	size_t	i;

	vec = ft_gc_helper();
	i = -1;
	while (++i < vec->total)
	{
		if (ptr == ((void **)vec->data)[i])
		{
			ft_memdel(&(((void **)vec->data)[i]));
			break ;
		}
	}
}
