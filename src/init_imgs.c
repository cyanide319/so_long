/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:25:38 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/02 10:14:32 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_img(t_data *img, t_map *map)
{
	map->p = mlx_xpm_file_to_image(img->mlx, "./ass_set/player.xpm",
			&map->img_x, &map->img_y);
	map->col = mlx_xpm_file_to_image(img->mlx, "./ass_set/collectible.xpm",
			&map->img_x, &map->img_y);
	map->e = mlx_xpm_file_to_image(img->mlx, "./ass_set/exit.xpm",
			&map->img_x, &map->img_y);
	map->bg = mlx_xpm_file_to_image(img->mlx, "./ass_set/floor.xpm",
			&map->img_x, &map->img_y);
	map->walls = mlx_xpm_file_to_image(img->mlx, "./ass_set/walls.xpm",
			&map->img_x, &map->img_y);
	put_img_on_map(img, map);
}

void	put_img_on_map(t_data *img, t_map *map)
{
	map->iy = 0;
	while (map->iy < map->y)
	{
		map->ix = 0;
		while (map->map[map->iy][map->ix] != '\n')
		{
			if (map->map[map->iy][map->ix] == 'C')
				img_select(img, map, 'C');
			else if (map->map[map->iy][map->ix] == 'P')
				img_select(img, map, 'P');
			else if (map->map[map->iy][map->ix] == 'E')
				img_select(img, map, 'E');
			else if (map->map[map->iy][map->ix] == '0')
				img_select(img, map, '0');
			else if (map->map[map->iy][map->ix] == '1')
				img_select(img, map, '1');
			map->ix++;
		}
		map->iy++;
	}
}

void	img_select(t_data *img, t_map *map, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(img->mlx, img->mlx_win, map->col,
			map->ix * 64, map->iy * 64);
	if (c == 'P')
		mlx_put_image_to_window(img->mlx, img->mlx_win, map->p,
			map->ix * 64, map->iy * 64);
	if (c == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, map->e,
			map->ix * 64, map->iy * 64);
	if (c == '0')
		mlx_put_image_to_window(img->mlx, img->mlx_win, map->bg,
			map->ix * 64, map->iy * 64);
	if (c == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, map->walls,
			map->ix * 64, map->iy * 64);
}
