/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:55:13 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/01/19 18:59:08 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_upper(char *row_str)
{
	while (*row_str)
	{
		*row_str = (char)ft_toupper(*row_str);
		row_str++;
	}
	return (row_str);
}
