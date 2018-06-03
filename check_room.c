/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 23:49:46 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/03 20:27:43 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem-in.h"

void	check_room(t_farm *farm, t_info *info)
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
	if (!(info->arr[0]) || !(ft_isnumber(info->arr[1]) && (ft_isnumber(info->arr[2]))))
	{
		farm->error = ft_strdup("Error");
		parsing_error_handler(farm, info);
	}
}
