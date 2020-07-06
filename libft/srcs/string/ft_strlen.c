/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 07:52:09 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str_ft.h"

size_t	ft_strlen(const char *str)
{
	register char *end;

	end = (char *)str;
	while (*end)
		++end;
	return (end - str);
}
