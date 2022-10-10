/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/10 16:13:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_quit(void)
{
	exit(0);
}

int	exit_escape(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		clean_quit();
	}
	return (0);
}

int	exit_x(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	clean_quit();
	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "Whatever");
	img.img = mlx_new_image(img.mlx, 1000, 1000);

	mlx_key_hook(img.mlx_win, exit_escape, &img);
	mlx_hook(img.mlx_win, 17, 0, exit_x, &img);
	mlx_loop(img.mlx);
}
