/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwsp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgalyeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:17:26 by rgalyeon          #+#    #+#             */
/*   Updated: 2018/12/07 21:46:01 by rgalyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		ft_count_word(char const *str)
{
	int count;
	int	flag;

	if (!str)
		return (0);
	count = 0;
	while (ft_isspace(*str))
		str++;
	flag = 0;
	while (*str)
	{
		if (ft_isspace(*str) == 0 && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (ft_isspace(*str))
			flag = 0;
		str++;
	}
	return (count);
}

static int		ft_word_size(char const *str)
{
	int i;

	i = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_isspace(*str) == 0 && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static char		**ft_initial(int *i, int *j, int count, char ***words)
{
	*i = 0;
	*j = 0;
	*words = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	if (!*words)
		return (NULL);
	return (*words);
}

static char		*ft_push_str(char const **s, char **word, int *i)
{
	while (ft_isspace(**s) && **s != '\0')
		(*s)++;
	while (ft_isspace(**s) == 0 && **s != '\0')
		(*word)[(*i)++] = *(*s)++;
	(*word)[*i] = '\0';
	return (*word);
}

char			**ft_splitwsp(char const *s)
{
	char	**words;
	char	*word;
	int		count;
	int		i;
	int		j;

	count = ft_count_word(s);
	if (!s || ft_initial(&i, &j, count, &words) == NULL)
		return (NULL);
	while (j < count)
	{
		if (!(word = (char *)ft_memalloc(sizeof(char) * (ft_word_size(s) + 1))))
		{
			i = -1;
			while (words[++i] && j--)
				free(words[i]);
			free(words);
			return (NULL);
		}
		word = ft_push_str(&s, &word, &i);
		words[j++] = word;
		i = 0;
	}
	words[count] = NULL;
	return (words);
}
