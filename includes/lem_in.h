/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:47:36 by yabdulha          #+#    #+#             */
/*   Updated: 2018/06/12 01:57:32 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>

# define ANTS 0
# define START 1
# define END 2
# define ROOM 3
# define COMMENT 4
# define LINK 5
# define ERROR 6
# define KRED  "\x1B[31m"
# define KNRM  "\x1B[0m"
# define MAX_ANTS	9999

# define SE			(1 << ('s' - 97))
# define CO			(1 << ('c' - 97))
# define PATH		(1 << ('p' - 97))
# define DEBUG		(1 << ('d' - 97))
# define HELP		(1 << ('h' - 97))
# define ROOMS		(1 << ('r' - 97))
# define AN			(1 << ('a' - 97))
# define ON			(1 << ('o' - 97))
# define NO			(1 << ('n' - 97))

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
	struct s_room	*parent;
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

typedef struct	s_path
{
	t_room			*room;
	int				o;
	struct s_path	*next;
}				t_path;

typedef struct	s_ant
{
	int				nb;
	t_path			*path;
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
	int				ants_no;
	t_room			*rooms;
	t_link			*links;
	int				flag : 4;
	t_room			*start;
	t_room			*end;
	t_data			**hashtable;
	int				room_no;
	int				flags;
	t_path			*path;
	t_link			*free;
}				t_farm;

int				options(char *s);

void			free_ht(t_farm *farm);
void			free_levels(t_link *level);
char			**split_line(char *s, char c);
void			free_arr(char **arr);
void			free_path(t_farm *farm);
void			free_info(t_info *info);
t_farm			*build_farm(void);
void			parsing_error_handler(t_farm *farm, t_info *info, char *error);
int				ft_hash(char *str, int rooms);
void			free_ht(t_farm *farm);

t_data			**create_ht(int size);
void			fill_hashtable(t_farm *farm, t_info *info);
void			read_link(t_farm *farm, t_info *info);
void			room(t_farm *farm, t_info *info);
void			detect_type(t_farm *farm, t_info *info);
void			print_usage(t_farm *farm);
void			read_input(t_farm *farm);
void			check_error(t_farm *farm);
t_link			*next_level(t_farm *farm, t_link *old, t_link *new);
int				solver(t_farm *farm, t_link *links, int depth);
t_link			*create_link(t_farm *farm, unsigned int hash,
		t_link *par);
void			save_link(t_farm *farm, t_link *head, unsigned int hash,
		t_link *par);
void			send_ants(t_farm *farm);
void			print_path(t_farm *farm);
void			check_room(t_farm *farm, t_info *info);
int				count_rooms(t_farm *farm);
void			add_room(t_farm *farm, t_info *info);
void			delete_room(t_farm *farm, t_room *room);

void			add_path(t_farm *farm, t_room *room);

void			add_ant(t_farm *farm, t_path *path, int nb);
void			delete_ant(t_farm *farm);

void			add_link(t_farm *farm, t_room *room, unsigned int hash);
void			delete_link(t_farm *farm, t_link *link);

#endif
