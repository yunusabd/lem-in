/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:48:37 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/02 00:11:21 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


static int		check_links(t_farm *farm, t_link *links)
{
	t_link	*tmp;

	tmp = links;
	printf("check links\n");
	while (tmp)
	{
		if (farm->hashtable[tmp->hash]->ptr == farm->end)
		{
			printf("last room: %s\n", farm->hashtable[tmp->hash]->ptr->s);
			while (tmp->par)
			{
				printf("par: %s\n", farm->hashtable[tmp->par->hash]->ptr->s);
				tmp->par = tmp->par->par;
			}
			return (1);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}

t_link			*next_level(t_farm *farm, t_link *old)
{
	t_link	*tmp;
	t_link	*tmp2;
	t_link	*new;

	tmp = old;
	new = NULL;
	printf("next level\n");
	while (tmp)
	{
		tmp2 = farm->hashtable[tmp->hash]->ptr->links;
		while (tmp2)
		{
			if (farm->hashtable[tmp2->hash]->ptr->visited == 0)
			{
				if (!new)
					new = create_link(farm, tmp2->hash, farm->hashtable[tmp->hash]->ptr, tmp);
				else
					save_link(farm, new, tmp2->hash, farm->hashtable[tmp->hash]->ptr, tmp);
				farm->hashtable[tmp2->hash]->ptr->visited = 1;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (new);
}


int				solver(t_farm *farm, t_link *links, int depth)
{
	t_link	*tmp;
	t_link	*tmp2;

	if (check_links(farm, links))
		return (1);
	else
	{
		// make new list for next level.
		links = next_level(farm, links);
		if (solver(farm, links, depth + 1))
			return (1);
	}
	return (0);
}
