/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:57:26 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 01:29:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*create_link(t_farm *farm, unsigned int hash,
		t_room *parent, t_link *par)
{
	t_link	*new;

	if (!(new = (t_link*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->hash = hash;
	new->parent = parent;
	new->par = par;
	if (parent)
		parent->visited = 1;
	new->next = NULL;
	return (new);
}

void	delete_link(t_farm *farm, t_link *cn)
{
	t_link	*tmp;

	tmp = farm->links;
	if ((farm->links))
	{
		while (tmp->next == cn)
			tmp = tmp->next;
		tmp->next = cn->next;
		free(cn);
		cn = NULL;
	}
}

void	save_link(t_farm *farm, t_link *head, unsigned int hash,
		t_room *parent, t_link *par)
{
	t_link	*new;
	t_link	*tmp;

	if (!head)
		return ;
	if (!(new = (t_link*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->hash = hash;
	new->parent = parent;
	new->par = par;
	parent->visited = 1;
	new->next = NULL;
	tmp = head;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	add_link(t_farm *farm, t_room *room, unsigned int hash)
{
	t_link	*new;
	t_link	*tmp;

	if (!room)
		return ;
	if (!(new = (t_link*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->hash = hash;
	new->parent = NULL;
	new->next = NULL;
	tmp = room->links;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	if (!(room->links))
		room->links = new;
	else
		tmp->next = new;
}
