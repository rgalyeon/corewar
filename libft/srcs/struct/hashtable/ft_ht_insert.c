/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:07:52 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	check_resize_up(t_hashtable *ht)
{
	const size_t load = ht->count * 100 / ht->size;

	if (load > 70)
		if (ft_ht_resize(ht, ht->base_size * 2) == -1)
			return (0);
	return (1);
}

/*
** Return 1 if pair (key:value) inserted;
** Return 0 if ft_ht_new_item return NULL
*/

int			ft_ht_insert(t_hashtable *ht, const char *key, const char *value)
{
	t_item			*item;
	t_item			*cur_item;
	int				index;
	int				attempt;

	if (!check_resize_up(ht) || !(item = ft_ht_new_item(key, value)))
		return (0);
	index = ft_ht_get_hash(item->key, (int)ht->size, 0);
	cur_item = ht->hashtable[index];
	attempt = 1;
	while (cur_item != NULL)
	{
		if (cur_item != ht->del_item && ft_strcmp(cur_item->key, key) == 0)
		{
			ft_del_item(cur_item);
			ht->hashtable[index] = item;
			return (1);
		}
		index = ft_ht_get_hash(item->key, (int)ht->size, attempt++);
		cur_item = ht->hashtable[index];
	}
	ht->hashtable[index] = item;
	ht->count += 1;
	return (1);
}
