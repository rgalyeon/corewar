/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_find_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 01:08:12 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_rb_node	*ft_rb_find_node(t_map *map, char *key)
{
	t_rb_node	*c;

	c = map->root;
	while (c != map->nil)
	{
		if (ft_strcmp(key, c->key) == 0)
			return (c);
		if (ft_strcmp(key, c->key) > 0)
			c = c->left;
		else
			c = c->right;
	}
	return (map->nil);
}
