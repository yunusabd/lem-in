/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:33:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/12 15:54:05 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (ft_count_char(info->line, '-') > 2)
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
	ft_printf("Options:\n");
	ft_printf("\t[-a]: Print number of ants\n");
	ft_printf("\t[-c]: Colorful ants\n");
	ft_printf("\t[-d]: Debug mode\n");
	ft_printf("\t[-h]: Help\n");
	ft_printf("\t[-n]: Suppress printing of input file contents\n");
	ft_printf("\t[-p]: Print path\n");
	ft_printf("\t[-r]: Print number of rooms\n");
	ft_printf("\t[-s]: Print start and end room\n");
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
	{
		if (farm->flags & NO)
			ft_printf("Start room: %s, end room: %s\n\n",
					farm->start->s, farm->end->s);
		else
			ft_printf("\nStart room: %s, end room: %s\n",
					farm->start->s, farm->end->s);
	}
}
