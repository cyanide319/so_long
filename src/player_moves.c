/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:25:58 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/03 20:58:21 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	find_player_pos(t_map *map)
{
	map->py = 1;
	while (map->map)
	{
		map->px = 1;
		while (map->px < (map->x - 1))
		{
			if (map->map[map->py][map->px] == 'P')
				return ;
			map->px++;
		}
		map->py++;
	}
}

void	move_right(t_map *map)
{
	if (map->map[map->py][map->px + 1] != '1')
	{
		if (map->map[map->py][map->px + 1] == 'E' &&
			map->collec == 0)
		{
			win_game(map);
		}
		if (map->map[map->py][map->px + 1] == 'E' &&
			map->collec != 0)
		{
			return ;
		}
		if (map->map[map->py][map->px + 1] == 'C')
			map->collec--;
		map->map[map->py][map->px] = '0';
		map->map[map->py][map->px + 1] = 'P';
		map->px++;
		map->mv++;
		ft_printf("Nb of move: %d\n", map->mv);
	}
}

void	move_left(t_map *map)
{
	if (map->map[map->py][map->px - 1] != '1')
	{
		if (map->map[map->py][map->px - 1] == 'E' &&
			map->collec == 0)
		{
			win_game(map);
		}
		if (map->map[map->py][map->px - 1] == 'E' &&
			map->collec != 0)
		{
			return ;
		}
		if (map->map[map->py][map->px - 1] == 'C')
			map->collec--;
		map->map[map->py][map->px - 1] = 'P';
		map->map[map->py][map->px] = '0';
		map->px--;
		map->mv++;
		ft_printf("Nb of move: %d\n", map->mv);
	}
}

void	move_up(t_map *map)
{
	if (map->map[map->py - 1][map->px] != '1')
	{
		if (map->map[map->py - 1][map->px] == 'E' &&
			map->collec == 0)
			win_game(map);
		if (map->map[map->py - 1][map->px] == 'E' &&
			map->collec != 0)
			return ;
		if (map->map[map->py - 1][map->px] == 'C')
			map->collec--;
		map->map[map->py][map->px] = '0';
		map->map[map->py - 1][map->px] = 'P';
		map->py--;
		map->mv++;
		ft_printf("Nb of move: %d\n", map->mv);
	}
}

void	move_down(t_map *map)
{
	if (map->map[map->py + 1][map->px] != '1')
	{
		if (map->map[map->py + 1][map->px] == 'E' &&
			map->collec == 0)
		{
			win_game(map);
		}
		if (map->map[map->py + 1][map->px] == 'E' &&
			map->collec != 0)
		{
			return ;
		}
		if (map->map[map->py + 1][map->px] == 'C')
			map->collec--;
		map->map[map->py][map->px] = '0';
		map->map[map->py + 1][map->px] = 'P';
		map->py++;
		map->mv++;
		ft_printf("Nb of move: %d\n", map->mv);
	}
}
