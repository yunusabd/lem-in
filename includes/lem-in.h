/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:47:36 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/03 20:19:04 by yabdulha         ###   ########.fr       */
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
# define START 1
# define END 2
# define ROOM 3
# define COMMENT 4
# define LINK 5
# define ERROR 6


# define VISUALIZER (1 << 0)
# define USAGE 	(1 << 1)
# define MOVES 	(1 << 2)
# define COLORS	(1 << 3)
# define HIDE 	(1 << 4)
# define SLOW 	(1 << 5)

typedef struct	s_room t_room;

typedef	struct	s_info
{
	char			*line;
	char			**arr;
	int				type : 8;
	int				line_no;
	int				x;
	int				y;
}				t_info;

typedef struct	s_link
{
	unsigned int	hash;
	t_room			*parent;
	struct s_link	*par;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	int				nb;
	char			*s;
	int				x;
	int				y;
	int				flag : 2;
	t_link			*links;
	int				visited;
	struct s_room	*next;
}				t_room;

typedef struct	s_ant
{
	int				nb;
	t_room			*room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_data
{
	unsigned int	key;
	t_room			*ptr;
}				t_data;

typedef struct	s_farm
{
	t_ant			*ants;
	t_room			*rooms;
	t_link			*links;	
	char			*error;
	int				flag : 4;
	t_room			*start;
	t_room			*end;
	t_data			**hashtable;
	int				room_no;
}				t_farm;

char			**split_line(char *s, char c);
void			free_arr(char **arr);
void			free_info(t_info *info);
t_farm			*build_farm(void);
void			parsing_error_handler(t_farm *farm, t_info *info);
int				ft_hash(char *str, int rooms);
void			free_ht(t_farm *farm);

t_data			**create_ht(int size);
void			fill_hashtable(t_farm *farm, t_info *info);
void			read_link(t_farm *farm, t_info *info);

t_link			*next_level(t_farm *farm, t_link *old);

int				solver(t_farm *farm, t_link *links, int depth);
t_link			*create_link(t_farm *farm, unsigned int hash, t_room *parent, t_link *par);
void			save_link(t_farm *farm, t_link *head, unsigned int hash, t_room *parent, t_link *par);

void			check_room(t_farm *farm, t_info *info);
int				count_rooms(t_farm *farm);
void			add_room(t_farm *farm, t_info *info);
void			delete_room(t_farm *farm, t_room *room);

void			add_ant(t_farm *farm, int nb);
void			delete_ant(t_farm *farm, t_ant *ant);

void			add_link(t_farm *farm, t_room *room, unsigned int hash);
void			delete_link(t_farm *farm, t_link *link);

#endif