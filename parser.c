/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:33:16 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 23:17:47 by yabdulha         ###   ########.fr       */
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

void	check_room(t_farm *farm, t_info *info, char **arr)
{
//TODO free arr
	if (ft_strchr(arr[0], '-'))
	{
		farm->error = ft_strdup("Dash in room name");
		parsing_error_handler(farm, );
	}
	if (!(ft_isnumber(arr[1]) && (ft_isnumber(arr[2]))))
	{
		farm->error = ft_strdup("Malformatted line");
		parsing_error_handler(farm, NULL);
	}
}

void	detect_type(t_farm *farm, t_info *info, char *s)
{
	char	**arr;

	if (ft_isnumber(s) && !ft_strchr(s, ' '))
		info->type = ANTS;
	else if (ft_strcmp(s, "##start") == 0)
		info->type = START;
	else if (ft_strcmp(s, "##end") == 0)
		info->type = END;
	else if (*s == '#')
		info->type = COMMENT;
	else if (ft_strchr(s, '-') && (!(ft_strchr(ft_strchr(s, '-') + 1, '-'))))
		info->type = LINK;
	// OR: check for dashes in room names, return error when there's a dash
	else
	{
		// Room + coordinates
		info->type = ROOM;
		arr = split_line(s, ' ');
		check_room(farm, info, arr);
//		while (arr)
//			printf("arr: %s\n", *(arr++));
	}
}

void	read_input(t_farm *farm)
{
	char	*line;
	t_info	*info;
	int		i = 0;


	while (get_next_line(0, &line) == 1)
	{
		info = (t_info*)malloc(sizeof(info));
		info->type = 0;
		detect_type(farm, info, line);

		printf("line %d type: %d\n", i++ + 1, info->type);
		free(info);
	}
}

int		main()
{
	t_farm	*farm;

	farm = build_farm();
	read_input(farm);
	return (0);	
}
