/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 01:25:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 01:29:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_rooms(t_farm *farm)
{
	int		i;
	t_room	*tmp;

	if (!farm || !(farm->rooms))
		return (0);
	i = 0;
	tmp = farm->rooms;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
