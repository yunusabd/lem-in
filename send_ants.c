/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:37:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/11 23:52:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Create ants, move them through the path.
*/

static void		create_ants(t_farm *farm)
{
	int		tmp;

	tmp = farm->ants_no;
	while (tmp)
		add_ant(farm, farm->path, tmp--);
}

static void		remove_ant(t_farm *farm, t_ant **ant)
{
	t_ant	*ptr;

	ptr = (*ant)->next;
	delete_ant(farm);
	*ant = ptr;
}

static void		print_ant(t_farm *farm, t_ant *tmp)
{
	(tmp != farm->ants) ? ft_printf(" ") : 0;
	if (farm->flags & CO)
		ft_printf("%s%d%sL%d-%s", "\x1B[", 31 + tmp->nb % 7, "m", tmp->nb,
				tmp->path->room->s);
	else
		ft_printf("L%d-%s", tmp->nb, tmp->path->room->s);
}

/*
** For each ant, check if the next room is empty, then move it.
*/

void			send_ants(t_farm *farm)
{
	t_ant	*tmp;

	create_ants(farm);
	tmp = farm->ants;
	while (farm->ants)
	{
		if (tmp->path->room == farm->end)
			remove_ant(farm, &tmp);
		else if (tmp->path->next->occupied == 0 ||
				tmp->path->next->room == farm->end)
		{
			tmp->path->occupied = 0;
			tmp->path = tmp->path->next;
			tmp->path->occupied = 1;
			print_ant(farm, tmp);
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
