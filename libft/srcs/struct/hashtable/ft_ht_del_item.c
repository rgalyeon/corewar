/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_del_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:42:47 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_del_item(t_item *item)
{
	ft_mem_free(item->key);
	ft_mem_free(item->value);
	ft_mem_free(item);
}
