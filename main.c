/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisupapi <sisupapi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:41:01 by sisupapi          #+#    #+#             */
/*   Updated: 2026/05/23 22:34:11 by sisupapi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_str_num(char *str);

int	main(int count, char **array)
{
	char	*num_str;
	char	*dict;

	dict = "numbers.dict";
	if (count == 2)
		num_str = array[1];
	else if (count == 3)
	{
		dict = array[1];
		num_str = array[2];
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_str_num(num_str) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
