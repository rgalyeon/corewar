/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 08:34:09 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 02:34:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void		ft_ht_all_delete(t_hashtable *ht)
{
	size_t	i;
	t_item	*item;

	i = -1;
	while (++i < ht->size)
	{
		item = ht->hashtable[i];
		if (item != NULL)
			ft_del_item(item);
	}
	ft_mem_free(ht->del_item);
	ft_mem_free(ht->hashtable);
	ft_mem_free(ht);
}
