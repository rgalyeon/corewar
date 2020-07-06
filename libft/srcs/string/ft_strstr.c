/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:48:24 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 04:38:12 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	register size_t	i;
	size_t			tmp;
	size_t			index_find;

	i = -1;
	if (!str || !to_find)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[++i] != '\0')
	{
		index_find = 0;
		if (str[i] == to_find[index_find])
		{
			tmp = i;
			while (str[i] == to_find[index_find])
			{
				if (to_find[index_find + 1] == '\0')
					return ((char *)&str[tmp]);
				++index_find && ++i;
			}
			i = tmp;
		}
	}
	return (NULL);
}
