/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:48:37 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/20 20:51:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_levels(t_link *level)
{
	t_link	*tmp;

	while (level)
	{
		tmp = level->next;
		free(level);
		level = tmp;
	}
}

static int		check_links(t_farm *farm, t_link *links)
{
	t_link	*tmp;

	tmp = links;
	while (tmp)
	{
		if (tmp->room == farm->end)
		{
			while (tmp->par)
			{
				add_path(farm, tmp->room);
				tmp = tmp->par;
			}
			add_path(farm, tmp->room);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_link			*next_level(t_farm *farm, t_link *old, t_link *new)
{
	t_link	*tmp;
	t_link	*tmp2;

	tmp = old;
	while (tmp)
	{
		tmp2 = tmp->room->links;
		while (tmp2)
		{
			if (tmp2->room->visited == 0)
			{
				if (!new)
					new = create_link(farm, tmp2->room, tmp);
				else
					save_link(farm, new, tmp2->room, tmp);
				tmp2->room->visited = 1;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (new);
}

int				solver(t_farm *farm, t_link *links, int depth)
{
	if (check_links(farm, links))
		return (1);
	else
	{
		if (!(links = next_level(farm, links, NULL)))
			parsing_error_handler(farm, NULL, "No path found");
		if (solver(farm, links, depth + 1))
		{
			free_levels(links);
			return (1);
		}
	}
	return (0);
}
