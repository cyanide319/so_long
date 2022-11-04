/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:25:38 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/03 20:32:43 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	check_img_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (false);
	close (fd);
	return (true);
}

void	check_img(void)
{
	if (check_img_file("./ass_set/player.xpm") == false
		|| check_img_file("./ass_set/collectible.xpm") == false
		|| check_img_file("./ass_set/exit.xpm") == false
		|| check_img_file("./ass_set/floor.xpm") == false
		|| check_img_file("./ass_set/walls.xpm") == false)
	{
		ft_printf("Something wrong with the xpm locations\n");
		exit (0);
	}
}

void	get_img(t_map *map)
{
	check_img();
	map->p = mlx_xpm_file_to_image(map->mlx, "./ass_set/player.xpm",
			&map->img_x, &map->img_y);
	map->p2 = mlx_xpm_file_to_image(map->mlx, "./ass_set/player2.xpm",
			&map->img_x, &map->img_y);
	map->col = mlx_xpm_file_to_image(map->mlx, "./ass_set/collectible.xpm",
			&map->img_x, &map->img_y);
	map->col2 = mlx_xpm_file_to_image(map->mlx, "./ass_set/exit.xpm",
			&map->img_x, &map->img_y);
	map->bg = mlx_xpm_file_to_image(map->mlx, "./ass_set/floor.xpm",
			&map->img_x, &map->img_y);
	map->bg2 = mlx_xpm_file_to_image(map->mlx, "./ass_set/floor2.xpm",
			&map->img_x, &map->img_y);
	map->walls = mlx_xpm_file_to_image(map->mlx, "./ass_set/walls.xpm",
			&map->img_x, &map->img_y);
	map->walls2 = mlx_xpm_file_to_image(map->mlx, "./ass_set/walls2.xpm",
			&map->img_x, &map->img_y);
	map->e = mlx_xpm_file_to_image(map->mlx, "./ass_set/exit2.xpm",
			&map->img_x, &map->img_y);
	map->e2 = mlx_xpm_file_to_image(map->mlx, "./ass_set/exit3.xpm",
			&map->img_x, &map->img_y);
	put_img_on_map(map);
}

void	put_img_on_map(t_map *map)
{
	map->iy = 0;
	while (map->iy < map->y)
	{
		map->ix = 0;
		while (map->map[map->iy][map->ix] != '\n')
		{
			if (map->map[map->iy][map->ix] == 'C')
				img_select(map, 'C');
			else if (map->map[map->iy][map->ix] == 'P')
				img_select(map, 'P');
			else if (map->map[map->iy][map->ix] == 'E')
				img_select(map, 'E');
			else if (map->map[map->iy][map->ix] == '0')
				img_select(map, '0');
			else if (map->map[map->iy][map->ix] == '1')
				img_select(map, '1');
			map->ix++;
		}
		map->iy++;
	}
}

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
}
