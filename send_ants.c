/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:37:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 01:29:15 by yabdulha         ###   ########.fr       */
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
	t_path	*ptr;

	create_ants(farm);
	tmp = farm->ants;
	while (farm->ants)
	{
		if (tmp->path->room == farm->end)
			delete_ant(farm, tmp);
		else if (tmp->path->next->occupied == 0 ||
				tmp->path->next->room == farm->end)
		{
			tmp->path->occupied = 0;
			tmp->path = tmp->path->next;
			tmp->path->occupied = 1;
			ft_printf("L%d-%s ", tmp->nb, tmp->path->room->s);
		}
		tmp = tmp->next;
		if (!(tmp))
		{
			tmp = farm->ants;
			ft_printf("\n");
		}
	}
}
