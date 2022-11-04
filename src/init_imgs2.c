/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:08:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 13:09:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_select(t_map *map, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->col,
			map->ix * 64, map->iy * 64);
	if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->p,
			map->ix * 64, map->iy * 64);
	if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->e,
			map->ix * 64, map->iy * 64);
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->bg,
			map->ix * 64, map->iy * 64);
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->walls,
			map->ix * 64, map->iy * 64);
	if (c == 'X')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->x_current,
			map->ix * 64, map->iy * 64);
}
