/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/02 16:57:08 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keybinds(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit (0);
	}
	if (keycode == 13)
	{
		move_up(map);
	}
	if (keycode == 1)
	{
		move_down(map);
	}
	if (keycode == 0)
	{
		move_left(map);
	}
	if (keycode == 2)
	{
		move_right(map);
	}
	return (0);
}

int	exit_x(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}

void	window_init(t_map *map)
{
	int	height;
	int	width;

	height = map->y * 64;
	width = map->x * 64;
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, width, height,
			"The sheep and the void");
}

void	win_game(t_map *map)
{
	ft_printf("Congrats and shit, you killed a sheep");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	map.mv = 0;
	map_open(&map, argc, argv);
	fucking_functions_function(&map);
	find_player_pos(&map);
	window_init(&map);
	get_img(&map);
	mlx_key_hook(map.mlx_win, keybinds, &map);
	mlx_hook(map.mlx_win, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
}
