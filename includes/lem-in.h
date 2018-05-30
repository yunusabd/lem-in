/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:47:36 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 23:00:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
#include <stdio.h> //TODO remove
# define ABS(X) (X < 0) ? -X : X

# define ANTS 0
# define ROOM 1
# define START 2
# define END 3
# define COMMENT 4
# define LINK 5
# define ERROR 6

# define VISUALIZER (1 << 0)
# define USAGE 	(1 << 1)
# define MOVES 	(1 << 2)
# define COLORS	(1 << 3)
# define HIDE 	(1 << 4)
# define SLOW 	(1 << 5)

typedef	struct	s_info
{
	char			*line;
	int				type : 8;
	int				no;
}				t_info;

typedef struct	s_room
{
	int				nb;
	char			*s;
	int				x;
	int				y;
	struct s_room	*next;
}				t_room;

typedef struct	s_ant
{
	int				nb;
	t_room			*room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_cn
{
	int				from;
	int				to;
	int				nb;
	struct s_cn		*next;
}				t_cn;

typedef struct	s_farm
{
	t_ant			*ants;
	t_room			*rooms;
	t_cn			*c;	
	char			*error;
}				t_farm;

char			**split_line(char *s, char c);
void			free_arr(char **arr);
t_farm			*build_farm(void);
void			parsing_error_handler(t_farm *farm, t_info *info);

void			add_room(t_farm *farm, int nb);
void			delete_room(t_farm *farm, t_room *room);

void			add_ant(t_farm *farm, int nb);
void			delete_ant(t_farm *farm, t_ant *ant);

void			add_cn(t_farm *farm, int nb);
void			delete_cn(t_farm *farm, t_cn *cn);
#endif
