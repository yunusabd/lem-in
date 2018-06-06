/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 23:49:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 01:29:15 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

static void	check_duplicate(t_farm *farm, t_info *info, char *name)
{
	t_room *tmp;

	tmp = farm->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->s, name) == 0)
		{
			farm->error = ft_strdup("Duplicate room name");
			parsing_error_handler(farm, info);
		}
		tmp = tmp->next;
	}
}

void		check_room(t_farm *farm, t_info *info)
{
	if (ft_count_char(info->line, ' ') > 1)
	{
		if (!(info->arr = split_line(info->line, ' ')))
			parsing_error_handler(farm, info);
	}
	else
		parsing_error_handler(farm, info);
	if (ft_strchr(info->arr[0], '-'))
	{
		if (!(farm->error = ft_strdup("Dash in room name")))
			farm->error = NULL;
		parsing_error_handler(farm, info);
	}
	if (!(info->arr[0]) ||
			(!(ft_isnumber(info->arr[1]) && (ft_isnumber(info->arr[2])))))
	{
		farm->error = ft_strdup("Error");
		parsing_error_handler(farm, info);
	}
	check_duplicate(farm, info, info->arr[0]);
}
