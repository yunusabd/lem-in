/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/11 22:08:39 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant	*create_ants(t_farm *farm, t_path *path, int nb)
{
	t_ant	*new;

	if (!(new = (t_ant*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL, NULL);
	new->nb = nb;
	new->path = path;
	new->next = NULL;
	return (new);
}

void			delete_ant(t_farm *farm)
{
	t_ant	*tmp;

	tmp = farm->ants;
	farm->ants = farm->ants->next;
	free(tmp);
	tmp = NULL;
}

void			add_ant(t_farm *farm, t_path *path, int nb)
{
	t_ant	*new;

	if (!(farm->ants))
		farm->ants = create_ants(farm, path, nb);
	else
	{
		if (!(new = (t_ant*)malloc(sizeof(*new))))
			parsing_error_handler(farm, NULL, NULL);
		new->nb = nb;
		new->path = path;
		new->next = farm->ants;
		farm->ants = new;
	}
}
