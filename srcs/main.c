/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 21:03:20 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/18 21:09:58 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(int ac, char **av)
{
	t_farm	*farm;
	t_link	*link;

	if (!(farm = build_farm()))
		return (0);
	while (--ac > 0)
		farm->flags |= options(av[ac]);
	(farm->flags & HELP) ? print_usage(farm) : 0;
	read_input(farm);
	check_error(farm);
	link = create_link(farm,
			ft_hash(farm->start->s, count_rooms(farm)), NULL);
	(farm->flags & NO) ? 0 : ft_printf("\n");
	solver(farm, link, 0);
	send_ants(farm);
	(farm->flags & AN) ? ft_printf("\n%d ants\n", farm->ants_no) : 0;
	(farm->flags & ROOMS) ? ft_printf("\n%d rooms\n", farm->room_no) : 0;
	(farm->flags & PATH) ? print_path(farm) : 0;
	free(link);
	parsing_error_handler(farm, NULL, "OK");
	return (0);
}
