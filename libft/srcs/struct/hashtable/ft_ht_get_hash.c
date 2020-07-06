/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_get_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:50:36 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/23 03:25:52 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int		ft_ht_get_hash(const char *str, const int size, const int attempt)
{
	const int hash1 = ft_ht_hash(str, PRIME_N1, size);
	const int hash2 = ft_ht_hash(str, PRIME_N2, size);

	return ((hash1 + (attempt * (hash2 + 1))) % size);
}
