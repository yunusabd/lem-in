/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:57:14 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/30 22:41:54 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Function to find fd in lst.
*/

struct s_list		*find_fd(int fd, t_list *lst)
{
	while (lst)
	{
		if (((t_fd*)lst->content)->fide == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/*
** Function to return a new list element, which stores a struct in the void*
** field of the libft list. It stores a file descriptor and the 'rest' string.
*/

t_list				*create_fd_elem(int fd)
{
	t_fd			fd_e;

	fd_e.fide = fd;
	fd_e.rest = ft_strnew(BUFF_SIZE);
	return (ft_lstnew(&fd_e, sizeof(t_fd)));
}

/*
** Reads from fd in a loop, until read returns 0 or a '\n' is found.
** In each iteration the newly read str is joined with the line.
*/

int					read_line(int fd, t_list *current, char **line)
{
	int				ret;
	char			*position;

	ret = 1;
	position = NULL;
	while (ret > 0 && !(position = ft_strchr(FD_ELEM->rest, '\n')))
	{
		*line = ft_strjoinfree(*line, FD_ELEM->rest, 1);
		ft_memset(FD_ELEM->rest, 0, BUFF_SIZE);
		ret = read(fd, FD_ELEM->rest, BUFF_SIZE);
	}
	if (ret <= 0)
	{
		if (*line[0])
		{
			free(FD_ELEM->rest);
			return (1);
		}
		return (ret);
	}
	*position = '\0';
	*line = ft_strjoinfree(*line, FD_ELEM->rest, 1);
	ft_strcpy(FD_ELEM->rest, position + 1);
	return (1);
}

/*
** Checks if fd exists in list. The 'current' variable stores the address of the
** list element (if it exists) or creates a new one.
** After some error checking the reading function is called.
*/

int					get_next_line(const int fd, char **line)
{
	static t_list	*head = NULL;
	t_list			*current;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || (!((*line) = ft_memalloc(1))))
		return (-1);
	if (!(current = find_fd(fd, head)))
		ft_lstadd(&head, (current = create_fd_elem(fd)));
	if (head == NULL || current == NULL || FD_ELEM->rest == NULL)
		return (-1);
	return (read_line(fd, current, line));
}
