/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:32:31 by rgalyeon          #+#    #+#             */
/*   Updated: 2020/01/30 15:59:20 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "char_ft.h"
# include "conv_ft.h"
# include "lst_ft.h"
# include "math_ft.h"
# include "matrix_ft.h"
# include "memory_ft.h"
# include "put_ft.h"
# include "rb_trees_ft.h"
# include "str_ft.h"
# include "vec_ft.h"
# include "sort_ft.h"
# include "hashtable_ft.h"
# include "get_next_line.h"

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

# define SUCCESS 0
# define MALLOC_ERR 1
# define FAILURE 2
# define READ_ERROR 3

typedef struct			s_string
{
	char	*s;
	size_t	len;
	size_t	cap;
}						t_string;

int						ft_vstrpb(t_string *str, char *s, size_t len);
void					ft_vstrdel(t_string **str);
char					*ft_vstrpopfront(t_string *str, size_t ind);
int						ft_vstrfind(t_string *str, char c);
t_string				*ft_makestr(const char *s, size_t len, size_t cap);

/*
** Colors
*/

/*
** Development utils
** for debugging or writing code
*/

void					do_nothing(void);

#endif
