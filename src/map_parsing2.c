/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:45:03 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/03 20:54:36 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	check_right_side(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		if (map->map[i][map->x - 1] != '1')
		{
			error(7, map);
		}
		i++;
	}
}

void	check_core(t_map *map)
{
	int		ix;
	int		iy;

	iy = 1;
	map->player = 0;
	map->collec = 0;
	map->exit = 0;
	while (iy < map->y - 1)
	{
		ix = 0;
		while (map->map[iy][ix] != '\n')
		{
			if (ix == map->x)
				error(9, map);
			else if (map->map[iy][ix] == 'C')
				map->collec++;
			else if (map->map[iy][ix] == 'P')
				map->player++;
			else if (map->map[iy][ix] == 'E')
				map->exit++;
			valid_comp(map->map[iy][ix]);
			ix++;
		}
		iy++;
	}
}

void	valid_comp(char c)
{
	char	*comp_set;
	int		i;

	comp_set = "01CPE";
	i = 0;
	while (comp_set[i])
	{
		if (c == comp_set[i])
			return ;
		i++;
	}
	write(2, "Error\n", 7);
	ft_printf("Bad component");
	exit (0);
}

void	check_components(t_map *map)
{
	if (map->collec < 1)
		error(10, map);
	if (map->player != 1)
		error(11, map);
	if (map->exit != 1)
		error(12, map);
}

void	check_file_format(char *str)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".ber";
	i = 0;
	j = 3;
	while (str[i] != '\0')
		i++;
	i--;
	while (j >= 0)
	{
		if (str[i] != comp[j])
		{
			write(2, "Error\n", 7);
			ft_printf("T'a map s'pas un .ber tarla");
			exit(0);
		}
		i--;
		j--;
	}
}
