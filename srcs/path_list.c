/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/12 01:58:10 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_path(t_farm *farm)
{
	t_path	*tmp;

	while (farm->path)
	{
		tmp = farm->path->next;
		free(farm->path);
		farm->path = tmp;
	}
}

static t_path	*create_path(t_farm *farm, t_room *room)
{
	t_path	*new;

	if (!(new = (t_path*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL, NULL);
	new->room = room;
	new->o = 0;
	new->next = NULL;
	return (new);
}

void			add_path(t_farm *farm, t_room *room)
{
	t_path	*new;

	if (!(farm->path))
		farm->path = create_path(farm, room);
	else
	{
		if (!(new = (t_path*)malloc(sizeof(*new))))
			parsing_error_handler(farm, NULL, NULL);
		new->room = room;
		new->o = 0;
		new->next = farm->path;
		farm->path = new;
	}
}
