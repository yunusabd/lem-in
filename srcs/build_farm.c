/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:32:21 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/10 21:04:06 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm	*build_farm(void)
{
	t_farm	*land;

	if (!(land = (t_farm*)malloc(sizeof(*land))))
		return (NULL);
	land->ants = NULL;
	land->ants_no = 0;
	land->rooms = NULL;
	land->links = NULL;
	land->flag = 0;
	land->flags = 0;
	land->room_no = 0;
	land->hashtable = NULL;
	land->start = NULL;
	land->end = NULL;
	land->path = NULL;
	return (land);
}
