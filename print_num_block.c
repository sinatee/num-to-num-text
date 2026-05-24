#include "map.h"

void	print_single(t_map *map, char c);
void	print_tens(t_map *map, char c);
void	print_two_digits(t_map *map, char *str);
void	print_three_digits(t_map *map, char *str);

void	print_single(t_map *map, char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	print(search_dict(map, str));
}

void	print_tens(t_map *map, char c)
{
	char	str[3];

	str[0] = c;
	str[1] = '0';
	str[2] = '\0';
	print(search_dict(map, str));
}

void	print_two_digits(t_map *map, char *str)
{
	char	teen[3];

	if (str[0] == '1')
	{
		teen[0] = str[0];
		teen[1] = str[1];
		teen[2] = '\0';
		print(search_dict(map, teen));
	}
	else 
	{
		print_tens(map, str[0]);
		if (str[1] != '0')
		{
			print(" ");
			print_single(map, str[1]);
		}
	}
}

void	print_three_digits(t_map *map, char *str)
{
	if (str[0] != '0')
	{
		print_single(map, str[0]);
		print(" ");
		print(search_dict(map, "100"));
		if (str[1] != '0' || str[2] != '0')
			print(" ");
	}
	if (str[1] == '0' && str[2] != '0')
		print_single(map, str[2]);
	else if (str[1] != '0')
		print_two_digits(map, str + 1);
}