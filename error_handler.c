/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:30:17 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 22:31:18 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		free_ants(t_farm *farm)
{
	t_ant	*tmp;

	if (farm->ants)
	{
		while (farm->ants)
		{
			tmp = farm->ants->next;
			free(farm->ants);
			farm->ants = tmp;
		}
		free(farm->ants);
	}
}

static void		free_rooms(t_farm *farm)
{
	t_room	*tmp;

	if (farm->rooms)
	{
		while (farm->rooms)
		{
			tmp = farm->rooms->next;
			free(farm->rooms);
			farm->rooms = tmp;
		}
		free(farm->rooms);
	}
}

void		free_c(t_farm *farm)
{
	t_cn	*tmp;

	if (farm->c)
	{
		while (farm->c)
		{
			tmp = farm->c->next;
			free(farm->c);
			farm->c = tmp;
		}
		free(farm->c);
	}
}

void			parsing_error_handler(t_farm *farm, t_info *info)
{
	if (!farm)
		exit(1);
	ft_printf("%s\n", farm->error);
	if ((farm->ants))
		free_ants(farm);
	if ((farm->rooms))
		free_rooms(farm);
	/*
	if ((farm->c))
		free_c(farm);
	if ((info))
	{
		free(info);
	}
	free(farm);
	*/
	exit(1);
}
