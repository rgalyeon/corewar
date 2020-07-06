/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_string_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 23:31:45 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/04/20 18:35:16 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_vec	*ft_vec_string_push(t_vec **vec, register char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (!ft_vec_push(vec, *str++))
			return (NULL);
	}
	return (*vec);
}
