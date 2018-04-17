/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:55:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/17 16:08:56 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdlib.h>
#include <limits.h>


typedef struct	s_clist
{
	int				data;
	char			c;
	struct s_clist	*next;
	struct s_clist	*prev;
	size_t			nb_elements;
}				t_clist;



/*
** Create, add to, and remove from Circular List
*/

t_clist*	create_clist(t_clist *tmp, int data);
void		add_before(t_clist *element, int data);
void		add_after(t_clist *element, int data);
void		add_to_head(t_clist *root, int data);
void		add_to_end(t_clist *root, int data);

void		remove_element(t_clist *element);
void		remove_first_element(t_clist *root);
void		remove_last_element(t_clist *root);

#endif
