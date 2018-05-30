/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:32:21 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 23:13:49 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_farm	*build_farm(void)
{
	t_farm	*land;

	land = (t_farm*)malloc(sizeof(land));
	land->ants = NULL;
	land->rooms = NULL;
	land->c = NULL;
	land->error = NULL;
	return (land);
}
