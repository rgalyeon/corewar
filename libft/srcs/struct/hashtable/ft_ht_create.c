/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 06:52:32 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 02:34:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_hashtable		*ft_ht_create(const size_t size)
{
	t_hashtable	*ht;

	if (!(ht = (t_hashtable *)ft_memalloc(sizeof(t_hashtable))))
		return (NULL);
	ht->base_size = size;
	ht->size = (size_t)ft_next_prime((int)ht->base_size);
	ht->count = 0;
	ht->hashtable = (t_item **)ft_memalloc(sizeof(t_item *) * ht->size);
	ht->del_item = (t_item *)ft_memalloc(sizeof(t_item));
	if (ht->del_item == NULL && ht->hashtable == NULL)
	{
		ft_mem_free(ht->hashtable);
		ft_mem_free(ht->del_item);
		ft_mem_free(ht);
		return (NULL);
	}
	ht->del_item->key = NULL;
	ht->del_item->value = NULL;
	return (ht);
}
