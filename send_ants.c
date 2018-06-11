/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:37:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/11 22:07:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Create ants, move them through the path.
*/

void	create_ants(t_farm *farm)
{
	int		tmp;

	tmp = farm->ants_no;
	while (tmp)
		add_ant(farm, farm->path, tmp--);
}

/*
** For each ant, check if the next room is empty, then move it.
*/

void	send_ants(t_farm *farm)
{
	t_ant	*tmp;
	t_ant	*ptr;
	int		i = 31;

	create_ants(farm);
	tmp = farm->ants;
	while (farm->ants)
	{
		if (tmp->path->room == farm->end)
		{
			ptr = tmp->next;
			delete_ant(farm);
			tmp = ptr;
		}
		else if (tmp->path->next->occupied == 0 ||
				tmp->path->next->room == farm->end)
		{
			tmp->path->occupied = 0;
			tmp->path = tmp->path->next;
			tmp->path->occupied = 1;
			(tmp != farm->ants) ? ft_printf(" ") : 0;
			(farm->flags & CO) ? ft_printf("%s%d%sL%d-%s", "\x1B[",
					i + tmp->nb % 7, "m", tmp->nb, tmp->path->room->s)
				: ft_printf("L%d-%s", tmp->nb, tmp->path->room->s);
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
		if (!(tmp))
		{
			tmp = farm->ants;
			(tmp) ? ft_printf("%s\n", KNRM) : 0;
		}
	}
}
