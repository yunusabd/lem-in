/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:30:17 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/03 20:18:38 by yabdulha         ###   ########.fr       */
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

void		free_links(t_farm *farm)
{
	t_link	*tmp;

	if (farm->links)
	{
		while (farm->links)
		{
			tmp = farm->links->next;
			free(farm->links);
			farm->links = tmp;
		}
		free(farm->links);
	}
}

void			free_info(t_info *info)
{
	int	i;

	i = 0;
	if ((info->line))
		free(info->line);
	free_arr(info->arr);
	free(info);
}

void			parsing_error_handler(t_farm *farm, t_info *info)
{
	if (!farm)
		exit(1);
	if (info)
		ft_printf("%s at line %d\n", farm->error, info->line_no);
	else
		ft_printf("Invalid input\n");
	if ((farm->ants))
		free_ants(farm);
	if ((farm->rooms))
		free_rooms(farm);
	if ((farm->links))
		free_links(farm);
	if ((info))
		free_info(info);
	free(farm->error);
	free(farm);
	while (1);
	exit(1);
}
