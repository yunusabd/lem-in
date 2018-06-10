/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:33:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/10 22:42:45 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void			room(t_farm *farm, t_info *info)
{
	if (!(ft_count_char(info->line, ' ') > 1) || (farm->hashtable))
		parsing_error_handler(farm, info, NULL);
	info->type = ROOM;
	check_room(farm, info);
	add_room(farm, info);
	free_arr(info->arr);
	free(info->arr);
	info->arr = NULL;
	farm->flag = 0;
}

void			detect_type(t_farm *farm, t_info *info)
{
	(!(farm->flags & NO)) ? ft_printf("%s\n", info->line) : 0;
	if (ft_count_char(info->line, '-') > 1)
		parsing_error_handler(farm, info, NULL);
	if (ft_isnumber(info->line))
	{
		if (farm->rooms || farm->hashtable)
			parsing_error_handler(farm, info, NULL);
		else
			farm->ants_no = ft_atoi(info->line);
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

void			print_usage(t_farm *farm)
{
	ft_printf("Usage:\t ./lem-in < input_file\n");
	ft_printf("\tOptions:\n");
	ft_printf("\t\t[-s]: Print start and end room\n");
	ft_printf("\t\t[-p]: Print path\n");
	ft_printf("\t\t[-r]: Print number of rooms\n");
	ft_printf("\t\t[-a]: Print number of ants\n");
	ft_printf("\t\t[-n]: Suppress printing of input file contents\n");
	ft_printf("\t\t[-h]: Help\n");
	parsing_error_handler(farm, NULL, NULL);
}

void			read_input(t_farm *farm)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(*info))))
		parsing_error_handler(farm, NULL, NULL);
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

void			check_error(t_farm *farm)
{
	if (!((farm->start)))
		parsing_error_handler(farm, NULL, "No start room specified");
	if (!((farm->end)))
		parsing_error_handler(farm, NULL, "No end room specified");
	if (farm->ants_no < 1)
		parsing_error_handler(farm, NULL, "Looks like there are no ants :(");
	if (farm->ants_no > MAX_ANTS)
		parsing_error_handler(farm, NULL, "Too many ants to simulate.");
	if (farm->flags & SE)
		ft_printf("Start room: %s, end room: %s\n",
				farm->start->s, farm->end->s);
}
