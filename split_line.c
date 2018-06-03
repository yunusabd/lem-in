/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:30:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/03 20:28:59 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static char	**ft_putwords(char *s, char c, char **arr, int words)
{
	char	*tmp;

	tmp = s;
	s += ft_strlen(s);
	arr[words--] = NULL;
	while (words && s != tmp)
	{
		while (*s && *s == c)
			s--;
		if (*s && *s != c)
		{
			while (s != tmp && *s != c)
				s--;
			if (!(arr[words] = ft_strdup(s)))
				return (NULL);
			if (s != tmp)
				*s = 0;
			words--;
		}
		else
			s--;
	}
	if (words > 0)
		arr[0] = NULL;
	else
		arr[0] = ft_strdup(tmp);
//	arr[0] = (words > 0) ? NULL : ft_strdup(tmp);
	return (arr);
}

void		free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (i < 3)
			free(arr[i++]);
	}
}

char		**split_line(char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(*arr) * (3 + 1))))
		return (NULL);
	if (!(ft_putwords(s, c, arr, 3)))
		return (NULL);
	return (arr);
}
