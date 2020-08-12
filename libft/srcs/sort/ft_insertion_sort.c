/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:31:02 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/08/12 15:35:28 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	ft_insertion_sort(int *data, unsigned int length)
{
	register int i;
	register int j;
	int 		key;

	i = 0;
	while (++i < length)
	{
		key = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
}

