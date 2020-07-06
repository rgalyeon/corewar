/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:02:58 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

/*
** Return key's value if the key is found;
** if key is not found return NULL
*/

char	*ft_ht_search(t_hashtable *ht, const char *key)
{
	int		index;
	t_item	*item;
	int		attempt;

	attempt = 0;
	index = ft_ht_get_hash(key, (int)ht->size, attempt++);
	item = ht->hashtable[index];
	while (item != NULL)
	{
		if (item != ht->del_item && ft_strcmp(item->key, key) == 0)
			return (item->value);
		index = ft_ht_get_hash(key, (int)ht->size, attempt++);
		item = ht->hashtable[index];
	}
	return (NULL);
}
