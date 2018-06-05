/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/04 23:26:55 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*create_rooms(t_farm *farm, t_info *info)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->nb = 0;
	new->s = ft_strdup(info->arr[0]);
	new->x = ft_atoi(info->arr[1]);
	new->y = ft_atoi(info->arr[2]);
	new->links = NULL;
	new->next = NULL;
	new->visited = 0;
	new->flag = farm->flag;
	(farm->flag == START) ? farm->start = new : 0;
	(farm->flag == END) ? farm->end = new : 0;
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

void	add_room(t_farm *farm, t_info *info)
{
	t_room		*new;
	t_room		*tmp;
	static int	i = 1;

	if (!(farm->rooms))
		farm->rooms = create_rooms(farm, info);
	else
	{
		if (!(new = (t_room*)malloc(sizeof(*new))))
			parsing_error_handler(farm, info);
		new->nb = i++;
		new->s = ft_strdup(info->arr[0]);
		new->x = ft_atoi(info->arr[1]);
		new->y = ft_atoi(info->arr[2]);
		new->flag = farm->flag;
		new->links = NULL;
		new->next = NULL;
		new->visited = 0;
		tmp = farm->rooms;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		(farm->flag == START) ? farm->start = new : 0;
		(farm->flag == END) ? farm->end = new : 0;
	}	
}
