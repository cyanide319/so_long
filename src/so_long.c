/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/25 18:40:41 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_quit(void)
{
	exit(0);
}

int	exit_escape(int keycode, t_data *img, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		clean_n_quit(map);
	}
	return (0);
}

int	exit_x(t_data *img, t_map *map)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	clean_n_quit(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	map;

	map.fd = 0;
	if (argc == 2)
	{
		map.fd = open(argv[1], O_RDONLY);
		if (map.fd == -1)
		{
			error (1, &map);
		}
		map_open(&map);
	}
	else
	{
		error (1, &map);
	}
	ft_bzero(&img, sizeof(t_data));
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "Whatever");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	mlx_key_hook(img.mlx_win, exit_escape, &img);
	mlx_hook(img.mlx_win, 17, 0, exit_x, &img);
	mlx_loop(img.mlx);
}
