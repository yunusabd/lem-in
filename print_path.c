/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 21:03:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/10 21:42:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void		print_path(t_farm *farm)
{
	t_path	*tmp;

	tmp = farm->path;
	while ((farm->flags & PATH) && tmp)
	{
		ft_printf("=> %s ", tmp->room->s);
		tmp = tmp->next;
	}
}
