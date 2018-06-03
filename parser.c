/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:33:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/03 20:18:14 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Detect the type of the line: 
** +Number of Ants
** +Room
** ##start or ##end
** # comment
** Links X-X
*/

#include "includes/lem-in.h"

void	detect_type(t_farm *farm, t_info *info)
{
	ft_printf("%s\n", info->line);
	if (ft_count_char(info->line, '-') > 1)
		parsing_error_handler(farm, info);
	if (!(farm->flag) && ft_isnumber(info->line) && (!(ft_strchr(info->line, ' '))))
		info->type = ANTS;
	else if (!(farm->flag) && ft_strcmp(info->line, "##start") == 0)
		farm->flag = START;
	else if (!(farm->flag) && ft_strcmp(info->line, "##end") == 0)
		farm->flag = END;
	else if (!(farm->flag) && *(info->line) == '#')
		info->type = COMMENT;
	else if (!(farm->flag) && ft_strchr(info->line, '-') &&
			(!(ft_count_char(info->line, '-'))))
		read_link(farm, info);
	else
	{
		if (!(ft_count_char(info->line, ' ') > 1))
			parsing_error_handler(farm, info);
		info->type = ROOM;
		check_room(farm, info);
		add_room(farm, info);
		farm->flag = 0;
	}
}

void	read_input(t_farm *farm)
{
	t_info	*info;

	info = (t_info*)malloc(sizeof(*info));
	info->line = NULL;
	info->x = 0;
	info->y = 0;
	info->line_no = 1;
	while (get_next_line(0, &(info->line)) == 1)
	{
		info->type = 0;
		info->arr = NULL;
		info->line_no++;
		detect_type(farm, info);
		free_arr(info->arr);
		free(info->arr);
		free(info->line);
		info->line = NULL;
	}
	free_info(info);
}

int		main()
{
	t_farm	*farm;
	int		rooms;
	t_link	*tmp;
	t_link	*link;
	t_link	*new;

	farm = build_farm();
	read_input(farm);
	if (!((farm->start) && (farm->end)))
		parsing_error_handler(farm, NULL);
	printf("start: %s, end: %s\n", farm->start->s, farm->end->s);
	tmp = farm->start->links;
	link = create_link(farm, ft_hash(farm->start->s, count_rooms(farm)), NULL, NULL);
	new = next_level(farm, link);
	solver(farm, new, 0);
	printf("rooms: %d\n", farm->room_no);
	free_ht(farm);
	parsing_error_handler(farm, NULL);
	return (0);	
}
