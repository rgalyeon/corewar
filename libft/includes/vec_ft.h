/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:26:06 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/05/19 22:36:23 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_FT_H
# define VEC_FT_H

typedef struct	s_vec
{
	void	*data;
	size_t	capacity;
	size_t	total;
	size_t	offset;
}				t_vec;

t_vec			*ft_vec_init(size_t capacity);
t_vec			*ft_vec_push(t_vec **vec, char c);
t_vec			*ft_ptr_vec_init(size_t capacity);
t_vec			*ft_ptr_vec_push(t_vec **vec, void *c);

t_vec			*vec_pro_init(size_t capacity);
t_vec			*vec_pro_push(t_vec **vec, void *c);
t_vec			*ft_vec_string_push(t_vec **vec, char *str);

#endif
