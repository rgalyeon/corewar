/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:44:20 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/16 11:46:07 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FT_H
# define SORT_FT_H

void	ft_swap(void *a, void *b);
void	ft_swaps(void *a, void *b, size_t size);
void	quick_sort_by_name(char **data, int len, short int r);

#endif
