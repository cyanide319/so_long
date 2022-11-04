/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_my_shorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:30:59 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/03 21:34:53 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_dup(t_map *map)
{
	char	**testmap;
	int		i;

	i = 0;
	testmap = malloc(sizeof(char *) * (map->y + 1));
	while (i < map->y)
	{
		testmap[i] = ft_strdup(map->map[i]);
		i++;
	}
	testmap[i] = NULL;
	return (testmap);
}

void	test_exit(t_map *map, char **testmap, int y, int x)
{
	if (testmap[y][x + 1] == 'E')
	{
		map->exitcheck++;
	}
	if (testmap[y][x - 1] == 'E')
	{
		map->exitcheck++;
	}
	if (testmap[y + 1][x] == 'E')
	{
		map->exitcheck++;
	}
	if (testmap[y - 1][x] == 'E')
	{
		map->exitcheck++;
	}
}

void	flood_map(t_map *map, char **testmap, int y, int x)
{
	testmap[y][x] = 'A';
	test_exit(map, testmap, y, x);
	if (testmap[y][x + 1] == '0' || testmap[y][x + 1] == 'C')
	{
		testmap[y][x + 1] = 'A';
		flood_map(map, testmap, y, x +1);
	}
	if (testmap[y][x - 1] == '0' || testmap[y][x - 1] == 'C')
	{
		testmap[y][x - 1] = 'A';
		flood_map(map, testmap, y, x - 1);
	}
	if (testmap[y + 1][x] == '0' || testmap[y + 1][x] == 'C')
	{
		testmap[y + 1][x] = 'A';
		flood_map(map, testmap, y + 1, x);
	}
	if (testmap[y - 1][x] == '0' || testmap[y - 1][x] == 'C')
	{
		testmap[y - 1][x] = 'A';
		flood_map(map, testmap, y - 1, x);
	}
}

void	bad_path(t_map *map, char **testmap)
{
	write (2, "Error\n", 7);
	ft_printf("No valid fucking path");
	free_array(&testmap);
	clean_n_quit(map);
}

void	check_valid_path(t_map *map)
{
	char	**testmap;
	int		x;
	int		y;

	y = 1;
	map->exitcheck = 0;
	testmap = map_dup(map);
	flood_map(map, testmap, map->py, map->px);
	if (map->exitcheck == 0)
		bad_path(map, testmap);
	while (y < map->y)
	{
		x = 1;
		while (x < map->x)
		{
			if (testmap[y][x] == '1' || testmap[y][x] == 'A'
				|| testmap[y][x] == 'E' || testmap[y][x] == '0')
				x++;
			else if (testmap[y][x] == 'C')
				bad_path(map, testmap);
		}
		y++;
	}
	free_array(&testmap);
}
