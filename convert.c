#include "map.h"

char	*search_dict(t_map *map, char *key);
void	print_number(t_map *map, char *num_str);
void	print_single(t_map *map, char c);
void	print_tens(t_map *map, char c);
void	print_two_digits(t_map *map, char *str);
void	print_three_digits(t_map *map, char *str);
void	print_scale(t_map *map, int zeros);
int		is_zero_block(char *str, int block_len);
void	print_block(t_map *map, char *num_str, int length, int block_len);

char	*search_dict(t_map *map, char *key)
{
	int	i = 0;

	i = 0;
	while (map[i].key != (void *)0)
	{
		if (cmp(map[i].key, key) == 0)
		{
			return (map[i].value);
		}
		i++;
	}
	return ((void *)0);
}

void	print_number(t_map *map, char *num_str)
{
	int	block_len;
	int	first;

	first = 1;
	num_str = skip_zeros(num_str);
	if (*num_str == '0')
	{
		print_single(map, '0');
		print("\n");
		return ;
	}
	while (*num_str != '\0')
	{
		block_len = (len(num_str) - 1) % 3 + 1;
		if (!is_zero_block(num_str, block_len))
		{
			if (!first)
				print(" ");
			print_block(map, num_str, len(num_str), block_len);
			first = 0;
		}
		num_str += block_len;
	}
	print("\n");
}

void	print_scale(t_map *map, int zeros)
{
	char	scale[40];
	int		i;

	scale[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		scale[i] = '0';
		i++;
	}
	scale[i] = '\0';
	print(" ");
	print(search_dict(map, scale));
}

int	is_zero_block(char *str, int block_len)
{
	int	i;

	i = 0;
	while (i < block_len)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	print_block(t_map *map, char *num_str, int length, int block_len)
{
	if (block_len == 1)
		print_single(map, num_str[0]);
	else if (block_len == 2)
		print_two_digits(map, num_str);
	else if (block_len == 3)
		print_three_digits(map, num_str);
	if (length > 3)
		print_scale(map, length - block_len);
}
