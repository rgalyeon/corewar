/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:39:20 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/25 23:37:44 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	gnl_del(int ret, t_string **str, char **hl)
{
	if (hl)
		free(*hl);
	if (str)
		ft_vstrdel(str);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static t_string	*str = 0;
	static int		ind = -1;
	int				f;
	char			*hl;

	if (!(hl = (char*)malloc(BUFF_SIZE)) || !line)
		return (-1);
	if (!str && !(str = ft_makestr(0, 0, 1)))
		return (gnl_del(-1, &str, &hl));
	f = 0;
	if (ind == -1 && ((!(f = (int)read(fd, hl, BUFF_SIZE)) &&
					!(str->len)) || (f < 0)))
		return (gnl_del(f < 0 ? -1 : 0, &str, &hl));
	f && ft_vstrpb(str, hl, f);
	free(hl);
	ind = ft_vstrfind(str, '\n');
	if (ind == -1 && f == BUFF_SIZE)
		return (get_next_line(fd, line));
	*line = ft_vstrpopfront(str, ind == -1 ? str->len : (size_t)ind + 1);
	if (!*line)
		gnl_del(-1, &str, &hl);
	ind == -1 ? 1 : !((*(*line + ind)) = 0) &&
	(ind = ft_vstrfind(str, '\n'));
	return (1);
}
