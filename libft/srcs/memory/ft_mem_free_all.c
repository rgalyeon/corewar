/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:37:39 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/21 06:04:41 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_mem_free_all(int err)
{
	const t_vec		*vec = ft_gc_helper();
	register size_t	i;
	const size_t	vec_len = vec->total;

	i = -1;
	while (++i < vec_len)
		free(((void **)vec->data)[i]);
	free(vec->data);
	free((void *)vec);
	if (err == MALLOC_ERR)
	{
		ft_putendl_fd("Malloc error", 2);
		exit(EXIT_FAILURE);
	}
	else if (err == READ_ERROR)
	{
		ft_putendl_fd("Read error", 2);
		exit(EXIT_FAILURE);
	}
	else if (err == SUCCESS)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
