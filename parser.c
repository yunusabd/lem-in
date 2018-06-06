/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:33:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 01:29:15 by yabdulha         ###   ########.fr       */
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

#include "includes/lem_in.h"

static void		room(t_farm *farm, t_info *info)
{
	if (!(ft_count_char(info->line, ' ') > 1) || (farm->hashtable))
		parsing_error_handler(farm, info);
	info->type = ROOM;
	check_room(farm, info);
	add_room(farm, info);
	free_arr(info->arr);
	free(info->arr);
	info->arr = NULL;
	farm->flag = 0;
}

void	detect_type(t_farm *farm, t_info *info)
{
	ft_printf("%s\n", info->line);
	if (ft_count_char(info->line, '-') > 1)
		parsing_error_handler(farm, info);
	if (info->line_no == 1)
	{
		if (ft_isnumber(info->line))
			farm->ants_no = ft_atoi(info->line);
		else
			parsing_error_handler(farm, info);
	}
	else if (!(farm->flag) && ft_strcmp(info->line, "##start") == 0)
		farm->flag = START;
	else if (!(farm->flag) && ft_strcmp(info->line, "##end") == 0)
		farm->flag = END;
	else if (*(info->line) == '#')
		info->type = COMMENT;
	else if (!(farm->flag) && ft_strchr(info->line, '-'))
		read_link(farm, info);
	else
		room(farm, info);
}

void	read_input(t_farm *farm)
{
	t_info	*info;

	info = (t_info*)malloc(sizeof(*info));
	info->line = NULL;
	info->x = 0;
	info->y = 0;
	info->line_no = 0;
	info->arr = NULL;
	while (get_next_line(0, &(info->line)) == 1)
	{
		info->type = 0;
		info->line_no++;
		detect_type(farm, info);
		free(info->line);
		info->line = NULL;
	}
	free_info(info);
}

void	check_error(t_farm *farm)
{
	if (!((farm->start)))
	{
		farm->error = ft_strdup("No start room specified");
		parsing_error_handler(farm, NULL);
	}
	if (!((farm->end)))
	{
		farm->error = ft_strdup("No end room specified");
		parsing_error_handler(farm, NULL);
	}
	if (farm->ants_no == 0)
	{
		farm->error = ft_strdup("Looks like there are no ants :(");
		parsing_error_handler(farm, NULL);
	}
	if (farm->flags & SE)
		ft_printf("start: %s, end: %s\n", farm->start->s, farm->end->s);
}

int		main(int ac, char **av)
{
	t_farm	*farm;
	t_path	*tmp;
	t_link	*link;

	farm = build_farm();
	while (--ac > 0)
		farm->flags |= options(av[ac]);
	read_input(farm);
	ft_printf("\n");
	check_error(farm);
	link = create_link(farm,
			ft_hash(farm->start->s, count_rooms(farm)), NULL, NULL);
	solver(farm, link, 0);
	send_ants(farm);
	if (farm->flags & ROOMS)
		printf("rooms: %d\n", farm->room_no);
	tmp = farm->path;
	while ((farm->flags & PATH) && tmp)
	{
		ft_printf("=> %s ", tmp->room->s);
		tmp = tmp->next;
	}
	free(link);
	parsing_error_handler(farm, NULL);
	return (0);
}
