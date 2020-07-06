/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:35:09 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/02/27 20:36:54 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdarg.h>

void	ft_putnstr(int n, ...)
{
	va_list	str;
	char	*tmp;

	va_start(str, n);
	while (n--)
	{
		tmp = va_arg(str, char *);
		ft_putstr(tmp);
	}
	va_end(str);
}
