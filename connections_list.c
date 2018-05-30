/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 01:47:06 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_cn		*create_c(t_farm *farm, int nb)
{
	t_cn	*new;

	if (!(new = (t_cn*)malloc(sizeof(*new))))
		parsing_error_handler(farm, NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void			delete_cn(t_farm *farm, t_cn *cn)
{
	t_cn	*tmp;

	tmp = farm->c;
	if ((farm->c))
	{
		while (tmp->next == cn)
			tmp = tmp->next;
		tmp->next = cn->next;
		free(cn);
		cn = NULL;
	}
}

void			add_cn(t_farm *farm, int nb)
{
	t_cn	*new;
	t_cn	*tmp;

	if (!(farm->c))
		farm->c = create_c(farm, nb);
	else
	{
		if (!(new = (t_cn*)malloc(sizeof(*new))))
			parsing_error_handler(farm, NULL);
		new->nb = nb;
		new->next = NULL;
		tmp = farm->c;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}	
}
