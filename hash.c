#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "lem-in.h"

int		ft_hash(char *str, int rooms)
{
	int				c;
	unsigned long	hash;

	(rooms < 100) ? rooms = 100 : 0;
	hash = 5381;
	while ((c = *(str++)))
		hash = hash * 33 + c;
	return ((unsigned int)(hash % (rooms * 100)));
}

t_data	*create_entry(t_room *ptr)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->ptr = ptr;
	return (new);
}

t_data	**create_ht(int size)
{
	int		i;
	t_data	**new;

	i = 0;
	if (!(new = (t_data**)malloc(sizeof(t_data) * size * 100)))
		return (NULL);
	while (i < (size *100))
		new[i++] = NULL;
	return (new);
}

void	fill_hashtable(t_farm *farm, t_info *info)
{
	t_room			*tmp;
	unsigned int	hash;

	tmp = farm->rooms;
	while (tmp != NULL)
	{
		hash = ft_hash(tmp->s, farm->room_no);
		if (!(farm->hashtable[hash] = create_entry(tmp)))
			parsing_error_handler(farm, info);
		tmp = tmp->next;
	}
}

//TODO
void	free_ht(t_farm *farm)
{
	t_room			*tmp;
	unsigned int	hash;

	tmp = farm->rooms;
	while (farm->rooms)
	{
		tmp = farm->rooms->next;
		hash = ft_hash(farm->rooms->s, farm->room_no);
		free(farm->hashtable[hash]);
		farm->rooms = tmp;
	}
	free(farm->hashtable);
}

/*
int		main(int argc, char **argv)
{
	printf("input: [%s], hash: [%d]\n", argv[1], ft_hash(argv[1], atoi(argv[2])));
	return (0);
}
*/
