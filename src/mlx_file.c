/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:19:13 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/03 20:19:46 by tbeaudoi         ###   ########.fr       */
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

int	update(t_map *map)
{
	swap_wall(map);
	usleep(76666);
	put_img_on_map(map);
	return (0);
}