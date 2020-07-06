/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 06:59:57 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:31:23 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/matrix_ft.h"

t_matrix	*ft_matrix_copy(t_matrix *array)
{
	t_matrix	*copy;
	size_t		i;
	size_t		j;

	if (!array || !(array->matrix) || (array->row == 0) || (array->col == 0))
		return (NULL);
	if (!(copy = ft_matrix_create(array->row, array->col)))
		return (NULL);
	i = -1;
	while (++i < array->row)
	{
		j = -1;
		while (++j < array->col)
			(copy->matrix)[i][j] = (array->matrix)[i][j];
	}
	copy->row = array->row;
	copy->col = array->col;
	return (copy);
}
