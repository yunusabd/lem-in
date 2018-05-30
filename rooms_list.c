/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 01:43:12 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*create_rooms(t_farm *farm, int nb)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	delete_room(t_farm *farm, t_room *room)
{
	t_room	*tmp;

	tmp = farm->rooms;
	if ((farm->rooms))
	{
		while (tmp->next == room)
			tmp = tmp->next;
		tmp->next = room->next;
		free(room);
		room = NULL;
	}
}

void	add_room(t_farm *farm, int nb)
{
	t_room	*new;
	t_room	*tmp;

	if (!(farm->rooms))
		farm->rooms = create_rooms(farm, nb);
	else
	{
		if (!(new = (t_room*)malloc(sizeof(*new))))
			parsing_error_handler(farm, NULL);
		new->nb = nb;
		new->next = NULL;
		tmp = farm->rooms;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}	
}
