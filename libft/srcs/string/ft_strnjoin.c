/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 08:05:51 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/05 20:30:19 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdarg.h>

char	*ft_strnjoin(int n, ...)
{
	va_list	str;
	char	*tmp;
	char	*new_str;

	va_start(str, n);
	tmp = va_arg(str, char *);
	new_str = ft_strdup(tmp);
	while (--n)
	{
		tmp = new_str;
		if (!(new_str = ft_strjoin(new_str, va_arg(str, char *))))
			return (NULL);
		ft_mem_free(tmp);
	}
	va_end(str);
	return (new_str);
}
