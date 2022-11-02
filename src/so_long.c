/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/02 10:53:25 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_escape(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	return (0);
}

int	exit_x(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit(0);
	return (0);
}

void	window_init(t_data *img, t_map *map)
{
	int	height;
	int	width;

	height = map->y * 64;
	width = map->x * 64;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, width, height,
			"The sheep and the void");
	// img->img = mlx_new_image(img->mlx, width, height);
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	map;

	map_open(&map, argc, argv);
	fucking_functions_function(&map);
	ft_bzero(&img, sizeof(t_data));
	window_init(&img, &map);
	get_img(&img, &map);
	mlx_key_hook(img.mlx_win, exit_escape, &img);
	mlx_hook(img.mlx_win, 17, 0, exit_x, &img);
	mlx_loop(img.mlx);
}
