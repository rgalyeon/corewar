/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:38:22 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 04:36:17 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_ht_print(t_hashtable *ht)
{
	size_t			i;
	const size_t	size = ht->size;
	t_item			*item;

	i = -1;
	while (++i < size)
	{
		item = ht->hashtable[i];
		if (item != NULL && item != ht->del_item)
		{
			ft_putnstr(4, item->key, "=", item->value, "\n");
		}
	}
}
