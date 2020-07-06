/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_ft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:36:21 by rgalyeon          #+#    #+#             */
/*   Updated: 2019/03/05 20:32:46 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_FT_H
# define HASHTABLE_FT_H
# include <stdlib.h>
# include <limits.h>
# define PRIME_N1 131
# define PRIME_N2 139

typedef struct	s_item
{
	char	*key;
	char	*value;
}				t_item;

typedef struct	s_hashtable
{
	size_t	size;
	size_t	count;
	size_t	base_size;
	t_item	*del_item;
	t_item	**hashtable;
}				t_hashtable;

t_hashtable		*ft_ht_create(size_t size);
void			ft_ht_all_delete(t_hashtable *ht);
void			ft_del_item(t_item *item);
int				ft_ht_hash(const char *str, int prime, int size);
int				ft_ht_get_hash(const char *key, int size, int attempt);
t_item			*ft_ht_new_item(const char *key, const char *value);
int				ft_ht_insert(t_hashtable *ht, const char *key, \
															const char *value);
int				ft_ht_delete(t_hashtable *ht, const char *key);
char			*ft_ht_search(t_hashtable *ht, const char *key);
int				ft_ht_resize(t_hashtable *ht, size_t base_size);
void			ft_ht_print(t_hashtable *ht);
#endif
