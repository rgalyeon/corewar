/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_print_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:07:57 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_rb_print_key(t_rb_node *root)
{
	if (root == NULL)
		return ;
	ft_rb_print_key(root->right);
	ft_putendl(root->key);
	ft_rb_print_key(root->left);
}
