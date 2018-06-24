/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_api.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:05:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/23 19:19:46 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Creates a t_data struct for stroring in the hashtable.
*/

t_data			*create_entry(t_room *ptr)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

/*
** Appends a room to an occupied spot in the hashtable, in case of a collision.
*/

t_data			*add_entry(t_data *head, t_room *ptr)
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

/*
** Retrieve an entry from the hash table.
*/

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
