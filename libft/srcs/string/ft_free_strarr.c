/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 08:57:49 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/05 20:24:36 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_strarr(char **str_arr)
{
	int		i;

	i = -1;
	while (str_arr[++i])
		ft_mem_free(str_arr[i]);
	ft_mem_free(str_arr);
}
