/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:20:32 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:34:16 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/matrix_ft.h"

t_matrix	*ft_matrix_sub(t_matrix *a, t_matrix *b)
{
	t_matrix	*new;
	size_t		i;
	size_t		j;

	if (!a || !b || !(a->matrix) || !(b->matrix) || !(a->col)
			|| !(a->row) || !(b->col) || !(b->row))
		return (NULL);
	if ((a->row != b->row) || (a->col != b->col))
		return (NULL);
	if (!(new = ft_matrix_create(a->row, a->col)))
		return (NULL);
	i = -1;
	while (++i < a->row)
	{
		j = -1;
		while (++j < a->col)
			(new->matrix)[i][j] = (a->matrix)[i][j] + (b->matrix)[i][j];
	}
	return (new);
}
