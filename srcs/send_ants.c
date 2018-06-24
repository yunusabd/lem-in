/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:37:11 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/23 19:01:41 by yabdulha         ###   ########.fr       */
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

/*
** Function for removing ants to call when they have reached the end room.
*/

static void		remove_ant(t_farm *farm, t_ant **ant)
{
	t_ant	*ptr;

	ptr = (*ant)->next;
	delete_ant(farm);
	*ant = ptr;
}

/*
** Before printing the current ant, put a space, except for the last ant.
** Two options to print with or withour color depending on the flag.
*/

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
** Set next room in path to occupied, set current room to free and move the
** pointer of the ant to point to the next room.
*/

static void		move_ant(t_farm *farm, t_ant **tmp)
{
	if ((*tmp)->path->room != farm->start)
		print_ant(farm, *tmp);
	(*tmp)->path->o = 0;
	(*tmp)->path = (*tmp)->path->next;
	(*tmp)->path->o = 1;
	(*tmp) = (*tmp)->next;
}

/*
** For each ant, check if it is at the end room. If not
** check if the next room is empty and move it.
*/

void			send_ants(t_farm *farm, t_ant *tmp)
{
	create_ants(farm);
	tmp = farm->ants;
	while (farm->ants)
	{
		if (tmp->path->room == farm->end)
		{
			print_ant(farm, tmp);
			remove_ant(farm, &tmp);
			if (farm->flags & CO)
				ft_printf((farm->ants) ? " " : "%s\n", KNRM);
			else
				ft_printf((farm->ants) ? " " : "\n");
		}
		else if (tmp->path->next->o == 0 || tmp->path->next->room == farm->end)
			move_ant(farm, &tmp);
		else
			tmp = tmp->next;
		if (!(tmp))
		{
			tmp = farm->ants;
			(tmp && (farm->flags & CO)) ? ft_printf("%s\n", KNRM) : 0;
			(tmp && !(farm->flags & CO)) ? ft_printf("\n") : 0;
		}
	}
}
