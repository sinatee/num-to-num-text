/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisupapi <sisupapi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:04:22 by sisupapi          #+#    #+#             */
/*   Updated: 2026/05/23 21:54:14 by sisupapi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_map
{
	char	*key;
	char	*value;
}	t_map;

void	print(char *str);
int		cmp(char *s1, char *s2);
int		len(char *str);
char	*search_dict(t_map *map, char *key);
void	print_number(t_map *map, char *num_str);
char	*skip_zeros(char *str);

#endif
