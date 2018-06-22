/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:12:37 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/20 21:11:32 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		create_hashtable(t_farm *farm, t_info *info, int size)
{
	if (!(farm->hashtable = create_ht(size)))
		parsing_error_handler(farm, info, NULL);
	fill_hashtable(farm, info);
}

static void		free_rooms(char **rooms)
{
	free(rooms[0]);
	free(rooms[1]);
	free(rooms);
}

void			read_link(t_farm *farm, t_info *info)
{
	char			**r;
	int				size;
	unsigned int	hash1;
	unsigned int	hash2;

	if (info->line && ft_count_char(info->line, '-') > 1)
		parsing_error_handler(farm, info, "Bad link");
	r = ft_strsplit(info->line, '-');
	if (farm->room_no == 0)
		farm->room_no = count_rooms(farm);
	if (!(r[0] && r[1]))
		parsing_error_handler(farm, info, "Invalid room");
	size = (farm->room_no < 100) ? 100 : farm->room_no;
	if (!(farm->hashtable))
		create_hashtable(farm, info, size);
	hash1 = ft_hash(r[0], size);
	hash2 = ft_hash(r[1], size);
	if (!(((farm->hashtable)[hash1]) && (farm->hashtable)[hash2]))
		parsing_error_handler(farm, info, "Negative coordinates / Bad link");
	add_link(farm, (ht(farm, r[0], hash1))->ptr, (ht(farm, r[1], hash2))->ptr);
	add_link(farm, (ht(farm, r[1], hash2))->ptr, (ht(farm, r[0], hash1))->ptr);
	free_rooms(r);
}
