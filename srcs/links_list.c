/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:57:26 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/20 20:52:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*create_link(t_farm *farm, t_room *room, t_link *par)
{
	t_link	*new;
	int		hash;

	if (!(new = (t_link*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL, NULL);
	hash = ft_hash(room->s, farm->room_no);
	new->room = room;
	new->hash = hash;
	new->par = par;
	if (par)
		par->room->visited = 1;
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

void	save_link(t_farm *farm, t_link *head, t_room *room, t_link *par)
{
	t_link	*new;
	t_link	*tmp;
	int		hash;

	if (!head)
		return ;
	if (!(new = (t_link*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL, NULL);
	hash = ft_hash(room->s, farm->room_no);
	new->hash = hash;
	new->par = par;
	new->room = room;
	if (par)
		par->room->visited = 1;
	new->next = NULL;
	tmp = head;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

/*
** Adds a link to a room.
*/

void	add_link(t_farm *farm, t_room *room, t_room *link)
{
	t_link	*new;
	t_link	*tmp;

	if (!room)
		return ;
	if (!(new = (t_link*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL, NULL);
	new->room = link;
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
