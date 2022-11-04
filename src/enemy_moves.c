/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:10:03 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 13:18:05 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_enemy_pos(t_map *map)
{
	map->ey = 1;
	while (map->map)
	{
		map->ex = 1;
		while (map->ex < (map->x - 1))
		{
			if (map->map[map->ey][map->ex] == 'X')
				return ;
			map->ex++;
		}
		map->ey++;
	}
}

void	enemy_moves(t_map *map, int mv_flag)
{
	if (mv_flag == 0 && (map->map[map->ey][map->ex + 1] == '0'
		|| map->map[map->ey][map->ex + 1] == 'P'))
	{
		e_move_right(map);
	}
	if (mv_flag == 1 && (map->map[map->ey][map->ex - 1] == '0'
		|| map->map[map->ey][map->ex - 1] == 'P'))
	{
		e_move_left(map);
	}
	if (mv_flag == 2 && (map->map[map->ey + 1][map->ex] == '0'
		|| map->map[map->ey + 1][map->ex] == 'P'))
	{
		e_move_up(map);
	}
	if (mv_flag == 3 && (map->map[map->ey - 1][map->ex] == '0'
		|| map->map[map->ey - 1][map->ex] == 'P'))
	{
		e_move_down(map);
	}
}

int	cheap_random(int s)
{
	static int	x = 42;
	int			a;
	int			m;
	int			c;

	c = s;
	m = 1117;
	a = 314;
	x = (a * x + c) % m;
	return ((a * x + c) % 4);
}

void	enemy_ctrl(t_map *map)
{
	int	flag;

	find_enemy_pos(map);
	flag = cheap_random(map->ex);
	if (flag == 0)
		map->x_current = map->x_r;
	if (flag == 1)
		map->x_current = map->x_l;
	if (flag == 2)
		map->x_current = map->x_d;
	if (flag == 3)
		map->x_current = map->x_u;
	enemy_moves(map, flag);
}
