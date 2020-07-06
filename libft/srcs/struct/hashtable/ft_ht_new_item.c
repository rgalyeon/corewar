/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_new_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:12:21 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_item	*ft_ht_new_item(const char *key, const char *value)
{
	t_item	*pair;

	if (!(pair = (t_item *)ft_memalloc(sizeof(t_item))))
		return (NULL);
	pair->key = ft_strdup(key);
	pair->value = ft_strdup(value);
	return (pair);
}
