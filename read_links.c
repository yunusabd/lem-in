/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:12:37 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/03 20:19:25 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	read_link(t_farm *farm, t_info *info)
{
	char	**rooms;
	int		size;
	t_data	*tmp;
	int		i;
	unsigned int	hash1;
	unsigned int	hash2;

	rooms = ft_strsplit(info->line, '-');
	if (farm->room_no == 0)
		farm->room_no = count_rooms(farm);
	if (!(rooms[0] && rooms[1]))
		parsing_error_handler(farm, info);
	size = (farm->room_no < 100) ? 100 : farm->room_no;
	if (!(farm->hashtable))
	{
		if (!(farm->hashtable = create_ht(size)))
			parsing_error_handler(farm, info);
		fill_hashtable(farm, info);
	}
	hash1 = ft_hash(rooms[0], size);
	hash2 = ft_hash(rooms[1], size);
	if (!(((farm->hashtable)[hash1]) && (farm->hashtable)[hash2]))
	{
		farm->error = ft_strdup("Link between nonexistent rooms");
		parsing_error_handler(farm, info);
	}
	add_link(farm, farm->hashtable[hash1]->ptr, hash2);
	add_link(farm, farm->hashtable[hash2]->ptr, hash1);
}
