#include "map.h"

void	dict_to_map(char *buff, t_map *map);
char	*get_key(char *buff, int *i);
char	*get_value(char *buff, int *i);
int		count_map(char *buff);

void	dict_to_map(char *buff, t_map *map)
{
	int	i;
	int	map_index;

	i = 0;
	map_index = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			i++;
			continue ;
		}
		map[map_index].key = get_key(buff, &i);
		while (buff[i] == ' ')
			i++;
		if (buff[i] == ':')
			i++;
		while (buff[i] == ' ')
			i++;
		map[map_index].value = get_value(buff, &i);
		map_index++;
	}
	map[map_index].key = (void *)0;
}

char	*get_key(char *buff, int *i)
{
	int		start;
	int		map_index;
	char	*key;

	start = *i;
	while (buff[*i] >= '0' && buff[*i] <= '9')
		(*i)++;
	key = malloc((*i) - start + 1);
	if (!key)
		return ((void *)0);
	map_index = 0;
	while (start < *i)
	{
		key[map_index] = buff[start];
		map_index++;
		start++;
	}
	key[map_index] = '\0';
	return (key);
}

char	*get_value(char *buff, int *i)
{
	int		start;
	int		end;
	int		map_index;
	char	*value;

	start = *i;
	while (buff[*i] != '\n' && buff[*i] != '\0')
		(*i)++;
	end = *i - 1;
	while (end >= start && buff[end] == ' ')
		end--;
	value = malloc(end - start + 2);
	if (!value)
		return ((void *)0);
	map_index = 0;
	while (start <= end)
	{
		value[map_index] = buff[start];
		map_index++;
		start++;
	}
	value[map_index] = '\0';
	return (value);
}

int	count_map(char *buff)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == ':')
			count++;
		i++;
	}
	return (count);
}
