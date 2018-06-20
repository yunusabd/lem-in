/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 00:49:00 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/20 19:37:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_hash(char *str, int rooms)
{
	int				c;
	unsigned long	hash;

	(rooms < 100) ? rooms = 100 : 0;
	hash = 5381;
	while ((c = *(str++)))
		hash = hash * 33 + c;
	return ((unsigned int)(hash % (rooms * 100)));
}

t_data			*create_entry(t_room *ptr)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

static t_data	*add_entry(t_data *head, t_room *ptr)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	while (head->next)
		head = head->next;
	head->next = new;
	return (new);
}

t_data			**create_ht(int size)
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

void			fill_hashtable(t_farm *farm, t_info *info)
{
	t_room			*tmp;
	unsigned int	hash;

	tmp = farm->rooms;
	while (tmp != NULL)
	{
		hash = ft_hash(tmp->s, farm->room_no);
		if (farm->hashtable[hash])
		{
			if (ft_strcmp(farm->hashtable[hash]->ptr->s, tmp->s) == 0)
				parsing_error_handler(farm, info, "Duplicateii room");
			else
			{
				if (!(add_entry(farm->hashtable[hash], tmp)))
					parsing_error_handler(farm, info, NULL);
			}
		}
		else if (!(farm->hashtable[hash] = create_entry(tmp)))
			parsing_error_handler(farm, info, NULL);
		tmp = tmp->next;
	}
}

t_data			*ht(t_farm *farm, char *key, unsigned int hash)
{
	t_data	*tmp;
	char	*l;

	if (!((farm->hashtable[hash])->next))
		return (farm->hashtable[hash]);
	tmp = farm->hashtable[hash];
	l = key;
	while ((tmp))
	{
		if (ft_strcmp(key, tmp->ptr->s) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void			free_ht(t_farm *farm)
{
	t_room			*tmp;
	t_data			*dmp;
	unsigned int	hash;

	tmp = farm->rooms;
	while (tmp)
	{
		hash = ft_hash(tmp->s, farm->room_no);
		while (farm->hashtable[hash])
		{
			dmp = farm->hashtable[hash]->next;
			free(farm->hashtable[hash]);
			farm->hashtable[hash] = dmp;
		}
		if (farm->hashtable[hash])
			free(farm->hashtable[hash]);
		tmp = tmp->next;
	}
	free(farm->hashtable);
}
