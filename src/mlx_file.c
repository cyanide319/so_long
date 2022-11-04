/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:19:13 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 16:31:57 by tbeaudoi         ###   ########.fr       */
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
	if (keycode == 13 || keycode == 126)
		move_up(map);
	if (keycode == 1 || keycode == 125)
		move_down(map);
	if (keycode == 0 || keycode == 123)
		move_left(map);
	if (keycode == 2 || keycode == 124)
		move_right(map);
	if (keycode == 46)
	{
		if (map->modeflag == 1)
			map->modeflag = 0;
		else if (map->modeflag == 0)
			map->modeflag = 1;
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
	ft_printf("Congrats and shit, you killed a sheep\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}

int	update(t_map *map)
{
	swap_p_x(map);
	if (map->modeflag == 1)
		swap_wall(map);
	if (map->xflag == 1)
		enemy_ctrl(map);
	usleep(76666);
	put_img_on_map(map);
	return (0);
}
