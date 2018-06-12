/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 00:49:00 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/07 17:32:25 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_hash(char *str, int rooms)
{
	int				c;
	unsigned long	hash;

	(rooms < 100) ? rooms = 100 : 0;
	hash = 5381;
	while ((c = *(str++)))
		hash = hash * 33 + c;
	return ((unsigned int)(hash % (rooms * 100)));
}

t_data	*create_entry(t_room *ptr)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->ptr = ptr;
	return (new);
}

t_data	**create_ht(int size)
{
	int		i;
	t_data	**new;

	i = 0;
	if (!(new = (t_data**)malloc(sizeof(t_data) * size * 100)))
		return (NULL);
	while (i < (size * 100))
		new[i++] = NULL;
	return (new);
}

void	fill_hashtable(t_farm *farm, t_info *info)
{
	t_room			*tmp;
	unsigned int	hash;

	tmp = farm->rooms;
	while (tmp != NULL)
	{
		hash = ft_hash(tmp->s, farm->room_no);
		if (!(farm->hashtable[hash] = create_entry(tmp)))
			parsing_error_handler(farm, info, NULL);
		tmp = tmp->next;
	}
}

void	free_ht(t_farm *farm)
{
	t_room			*tmp;
	unsigned int	hash;

	tmp = farm->rooms;
	while (tmp)
	{
		hash = ft_hash(tmp->s, farm->room_no);
		free(farm->hashtable[hash]);
		tmp = tmp->next;
	}
	free(farm->hashtable);
}
