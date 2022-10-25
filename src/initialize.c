/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:08 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/25 17:57:39 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_open(int fd, t_map *map)
{
	char	*temp;

	map->map = malloc(sizeof(char *) * 500);
	temp = ft_get_next_line(fd);
	map->y = 0;
	if (temp == NULL)
	{
		free (temp);
		error(fd, 3, map);
	}
	while (temp)
	{
		map->map[map->y] = temp;
		map->y++;
		if (map->y > 500)
		{
			error(fd, 2, map);
		}
		free (temp);
		temp = ft_get_next_line(fd);
	}
	free (temp);
	if (map->map[0] == NULL || map->map[0][0] == '\n')
		error(fd, 3, map);
}
