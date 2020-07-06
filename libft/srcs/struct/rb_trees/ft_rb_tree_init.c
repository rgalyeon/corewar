/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:49:41 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/rb_trees_ft.h"

t_map	*ft_rb_tree_init(void)
{
	t_map	*tree;

	tree = (t_map *)malloc(sizeof(t_map));
	if (!tree)
		return (NULL);
	tree->nil = (t_rb_node *)malloc(sizeof(t_rb_node));
	if (!(tree->nil))
	{
		free(tree);
		return (NULL);
	}
	tree->nil->color = RB_BLACK;
	tree->nil->right = NULL;
	tree->nil->left = NULL;
	tree->nil->parent = NULL;
	tree->nil->key = NULL;
	tree->size = 0;
	tree->nil->data = NULL;
	tree->root = tree->nil;
	return (tree);
}
