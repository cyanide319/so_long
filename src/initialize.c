/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:08 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/25 18:40:55 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_open(t_map *map)
{
	char	*temp;

	map->map = malloc(sizeof(char *) * 500);
	temp = ft_get_next_line(map->fd);
	map->y = 0;
	if (temp == NULL)
	{
		free (temp);
		error(3, map);
	}
	while (temp)
	{
		map->map[map->y] = temp;
		map->y++;
		if (map->y > 500)
		{
			error(2, map);
		}
		free (temp);
		temp = ft_get_next_line(map->fd);
	}
	free (temp);
	if (map->map[0] == NULL || map->map[0][0] == '\n')
		error(3, map);
}
