/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 13:59:22 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	variable_init(t_map *map)
{
	map->mv = 0;
	map->modeflag = 0;
	map->xflag = 0;
	map->player = 0;
	map->collec = 0;
	map->exit = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	variable_init(&map);
	map_open(&map, argc, argv);
	fucking_functions_function(&map);
	window_init(&map);
	get_img(&map);
	mlx_key_hook(map.mlx_win, keybinds, &map);
	mlx_hook(map.mlx_win, 17, 0, exit_x, &map);
	mlx_loop_hook(map.mlx, update, &map);
	mlx_loop(map.mlx);
}
