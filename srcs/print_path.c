/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 21:03:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/12 15:54:20 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_path(t_farm *farm)
{
	t_path	*tmp;

	tmp = farm->path;
	ft_printf("\nPath: ");
	while ((farm->flags & PATH) && tmp)
	{
		if (tmp != farm->path)
			ft_printf("=> %s", tmp->room->s);
		else
			ft_printf("%s", tmp->room->s);
		tmp = tmp->next;
		if (tmp)
			ft_printf(" ");
	}
	ft_printf("\n");
}
