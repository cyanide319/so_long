/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:10:31 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 15:21:32 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	fucking_functions_function(t_map *map)
{
	check_top(map);
	check_left_side(map);
	check_bot(map);
	top_x_bottom(map);
	check_right_side(map);
	check_core(map);
	check_components(map);
	find_player_pos(map);
	check_valid_path(map);
}

void	check_top(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\n')
		i++;
	map->x_top = i;
	if (map->x_top > 50)
		error(2, map);
	i = 0;
	while (i < map->x_top)
	{
		if (map->map[0][i] != '1')
		{
			error(4, map);
		}
		i++;
	}
}

void	check_left_side(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		if (map->map[i][0] != '1')
		{
			error(7, map);
		}
		i++;
	}
}

void	check_bot(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[map->y - 1][i] != '\0')
		i++;
	map->x_bot = i;
	i = 0;
	while (i < map->x_top)
	{
		if (map->map[map->y - 1][i] != '1')
		{
			error(5, map);
		}
		i++;
	}
}

void	top_x_bottom(t_map *map)
{
	if (map->x_top != map->x_bot)
	{
		error(6, map);
	}
	else
		map->x = map->x_top;
}
