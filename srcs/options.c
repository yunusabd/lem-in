/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:55:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 01:29:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** If the first character is '-', check if it is an options argument and set
** the flags accordingly. Return 0 if there's not a character after the dash.
*/

int	options(char *s)
{
	int	i;
	int	res;

	if (s[0] != '-')
		return (0);
	i = 1;
	res = 0;
	while (s[i] != '\0')
	{
		if (!ft_isalpha(s[(i)]))
			return (0);
		res |= (1 << (s[i] - 97));
		i++;
	}
	return (res);
}
