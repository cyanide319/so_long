/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:20:34 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 11:07:45 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	swap_wall(t_map *map)
{
	void	*temp;
	void	*temp2;
	void	*temp4;
	void	*temp5;

	temp = map->walls;
	map->walls = map->walls2;
	map->walls2 = temp;
	temp2 = map->col;
	map->col = map->col2;
	map->col2 = temp2;
	temp4 = map->bg;
	map->bg = map->bg2;
	map->bg2 = temp4;
	temp5 = map->e;
	map->e = map->e2;
	map->e2 = temp5;
}

void	swap_p_x(t_map *map)
{
	void	*temp;

	temp = map->p;
	map->p = map->p2;
	map->p2 = temp;
}

void	lose_game(t_map *map)
{
	ft_printf("Do you look back at your life sometimes\n");
	ft_printf("and think about how much\n");
	ft_printf("you suck at everything?\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}
