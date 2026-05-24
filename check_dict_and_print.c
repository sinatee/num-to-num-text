
#include "map.h"

void	check_dict_and_print(char *dict, char *num_str);
char	*get_valid_buff(char *dict);
int		get_dict_size(char *dict);
char	*store_dict_to_buff(char *dict, int size);
int		check_dict(char *buff);
int		helper_check_dict(char *buff, int *i);
int		count_map(char *buff);
void	dict_to_map(char *buff, t_map *map);

void	check_dict_and_print(char *dict, char *num_str)
{
	char	*buff;
	int		map_array_size;
	t_map	*map;

	buff = get_valid_buff(dict);
	if (!buff)
		return ;
	map_array_size = count_map(buff);
	map = malloc(sizeof(t_map) * (map_array_size + 1));
	if (!map)
	{
		free(buff);
		return ;
	}
	dict_to_map(buff, map);
	print_number(map, num_str);
	free(map); 
	free(buff);
}

char	*get_valid_buff(char *dict)
{
	int		dict_size;
	char	*buff;

	dict_size = get_dict_size(dict);
	if (dict_size == -1)
	{
		write(1, "Dict Error\n", 11);
		return ((void *)0);
	}
	buff = store_dict_to_buff(dict, dict_size);
	if (!buff)
		return ((void *)0);
	if (check_dict(buff) == -1)
	{
		write(1, "Dict Error\n", 11);
		free(buff);
		return ((void *)0);
	}
	return (buff);
}

int		check_dict(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			i++;
			continue ;
		}
		if (helper_check_dict(buff, &i) == -1)
			return (-1);
	}
	return (1);
}

int		helper_check_dict(char *buff, int *i)
{
	if (buff[*i] < '0' || buff[*i] > '9')
		return (-1);
	while (buff[*i] >= '0' && buff[*i] <= '9')
		(*i)++;
	while (buff[*i] == ' ')
		(*i)++;
	if (buff[*i] != ':')
		return (-1);
	(*i)++;
	while (buff[*i] == ' ')
		(*i)++;
	while (buff[*i] != '\n' && buff[*i] != '\0')
	{
		if (buff[*i] < 32 || buff[*i] > 126)
			return (-1);
		(*i)++;
	}
	return (1);
}
