/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_node_creat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:01:43 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_rb_node	*ft_rb_node_creat(t_map *map, char *key)
{
	t_rb_node	*new;

	if (!(new = (t_rb_node *)malloc(sizeof(t_rb_node))))
		return (NULL);
	new->color = RB_RED;
	new->left = map->nil;
	new->right = map->nil;
	new->parent = map->nil;
	if (!(new->key = ft_strdup(key)))
		return (NULL);
	new->data = map->nil;
	map->size += 1;
	return (new);
}
