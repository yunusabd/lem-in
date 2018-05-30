/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:18:50 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 21:56:21 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if a given string is a number, only allow minus, plus and spaces.
*/

int		ft_isnumber(char *s)
{
	if (!s || !(*s))
		return (0);
	while (*s && *s < 33)
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!(ft_isdigit(*s) || *s == ' '))
			return (0);
		else
			s++;
	}
	return (1);
}
