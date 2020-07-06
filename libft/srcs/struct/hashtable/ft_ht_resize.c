/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:26:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int		ft_ht_resize(t_hashtable *ht, const size_t base_size)
{
	t_hashtable		*new_ht;
	size_t			i;
	t_item			*item;
	const size_t	tmp_size = ht->size;
	const t_item	**tmp_items = (const t_item **)ht->hashtable;

	if (base_size < ht->base_size)
		return (0);
	if (!(new_ht = ft_ht_create(base_size)))
		return (-1);
	i = -1;
	while (++i < ht->size)
	{
		item = ht->hashtable[i];
		if (item != NULL && item != ht->del_item)
			ft_ht_insert(new_ht, item->key, item->value);
	}
	ht->base_size = new_ht->base_size;
	ht->count = new_ht->count;
	ht->size = new_ht->size;
	new_ht->size = tmp_size;
	ht->hashtable = new_ht->hashtable;
	new_ht->hashtable = (t_item **)tmp_items;
	ft_ht_all_delete(new_ht);
	return (1);
}
