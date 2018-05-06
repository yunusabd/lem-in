/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 21:36:18 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(t_frame *stacks)
{
	if (!(stacks->b))
		return ;
	if (stacks->a)
		add_to_top(&stacks->a, stacks->b->data, stacks);
	else
		stacks->a = create_clist(stacks->b->data, stacks);
	remove_head(&(stacks->b));
}

void		pb(t_frame *stacks)
{
	if (!(stacks->a))
		return ;
	if (stacks->b)
		add_to_top(&stacks->b, stacks->a->data, stacks);
	else
		stacks->b = create_clist(stacks->a->data, stacks);
	remove_head(&(stacks->a));
}
