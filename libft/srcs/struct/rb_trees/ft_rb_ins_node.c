/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_ins_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:54:44 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static void	left_or_right(t_rb_node *new, t_rb_node *sb)
{
	new->parent = sb;
	if (ft_strcmp(new->key, sb->key) > 0)
		sb->left = new;
	else
		sb->right = new;
}

t_rb_node	*ft_rb_ins_node(t_map *map, char *key)
{
	t_rb_node	*new;
	t_rb_node	*rt;
	t_rb_node	*sb;

	if (map->root == map->nil)
	{
		if (!(new = ft_rb_node_creat(map, key)))
			return (NULL);
		new->color = RB_BLACK;
		map->root = new;
		return (new);
	}
	rt = map->root;
	while (rt != map->nil)
	{
		sb = rt;
		if (ft_strcmp(sb->key, key) == 0)
			return (sb);
		rt = ((ft_strcmp(key, rt->key) > 0 ? rt->left : rt->right));
	}
	if (!(new = ft_rb_node_creat(map, key)))
		return (NULL);
	left_or_right(new, sb);
	ft_rb_ins_fix(map, new);
	return (new);
}
