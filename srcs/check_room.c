/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 23:49:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/12 15:54:32 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_duplicate(t_farm *farm, t_info *info)
{
	t_room *tmp;

	tmp = farm->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->s, info->arr[0]) == 0)
			parsing_error_handler(farm, info, "Duplicate room names");
		else if (tmp->x == ft_atoi(info->arr[1]) &&
				tmp->y == ft_atoi(info->arr[2]))
			parsing_error_handler(farm, info, "Duplicate coordinates");
		tmp = tmp->next;
	}
}

void		check_room(t_farm *farm, t_info *info)
{
	if (ft_count_char(info->line, ' ') > 1)
	{
		if (!(info->arr = split_line(info->line, ' ')))
			parsing_error_handler(farm, info, NULL);
	}
	else
		parsing_error_handler(farm, info, "Invalid room");
	if (!(info->arr) || !(info->arr[0]))
		parsing_error_handler(farm, info, NULL);
	if (info->arr[0][0] == 'L')
		parsing_error_handler(farm, info, "Room name can't start with 'L'");
	if (ft_strchr(info->arr[0], '-'))
		parsing_error_handler(farm, info, "Dash in room name");
	if (!(info->arr[0]) ||
			(!(ft_isnumber(info->arr[1]) && (ft_isnumber(info->arr[2])))))
		parsing_error_handler(farm, info, "Error");
	check_duplicate(farm, info);
}
