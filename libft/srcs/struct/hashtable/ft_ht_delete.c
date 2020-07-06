/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:51:25 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	check_resize_down(t_hashtable *ht)
{
	const size_t load = ht->count * 100 / ht->size;

	if (load < 10)
		if (ft_ht_resize(ht, ht->base_size / 2) == -1)
			return (0);
	return (1);
}

/*
** Return 1 if pair deleted;
** Return 0 resize not success;
*/

int			ft_ht_delete(t_hashtable *ht, const char *key)
{
	t_item	*item;
	int		index;
	int		attempt;

	if (!check_resize_down(ht))
		return (0);
	attempt = 0;
	index = ft_ht_get_hash(key, (int)ht->size, attempt++);
	item = ht->hashtable[index];
	while (item != NULL)
	{
		if (item != ht->del_item && ft_strcmp(item->key, key) == 0)
		{
			ft_del_item(item);
			ht->hashtable[index] = ht->del_item;
			ht->count--;
			return (1);
		}
		index = ft_ht_get_hash(key, (int)ht->size, attempt++);
		item = ht->hashtable[index];
	}
	return (1);
}
