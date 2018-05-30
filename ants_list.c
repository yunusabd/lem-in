/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 01:45:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_ant	*create_ants(t_farm *farm, int nb)
{
	t_ant	*new;

	if (!(new = (t_ant*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void			delete_ant(t_farm *farm, t_ant *ant)
{
	t_ant	*tmp;

	tmp = farm->ants;
	if ((farm->ants))
	{
		while (tmp->next == ant)
			tmp = tmp->next;
		tmp->next = ant->next;
		free(ant);
		ant = NULL;
	}
}

void			add_ant(t_farm *farm, int nb)
{
	t_ant	*new;
	t_ant	*tmp;

	if (!(farm->ants))
		farm->ants = create_ants(farm, nb);
	else
	{
		if (!(new = (t_ant*)malloc(sizeof(*new))))
			parsing_error_handler(farm, NULL);
		new->nb = nb;
		new->next = NULL;
		tmp = farm->ants;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}	
}
