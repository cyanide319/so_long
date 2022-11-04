/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:19:12 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 13:06:19 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	e_move_right(t_map *map)
{
	if (map->map[map->ey][map->ex + 1] == 'P')
		lose_game(map);
	map->map[map->ey][map->ex] = '0';
	map->map[map->ey][map->ex + 1] = 'X';
	map->ex++;
}

void	e_move_left(t_map *map)
{
	if (map->map[map->ey][map->ex - 1] == 'P')
		lose_game(map);
	map->map[map->ey][map->ex] = '0';
	map->map[map->ey][map->ex - 1] = 'X';
	map->ex--;
}

void	e_move_up(t_map *map)
{
	if (map->map[map->ey + 1][map->ex] == 'P')
		lose_game(map);
	map->map[map->ey][map->ex] = '0';
	map->map[map->ey + 1][map->ex] = 'X';
	map->ey++;
}

void	e_move_down(t_map *map)
{
	if (map->map[map->ey - 1][map->ex] == 'P')
		lose_game(map);
	map->map[map->ey][map->ex] = '0';
	map->map[map->ey - 1][map->ex] = 'X';
	map->ey--;
}
