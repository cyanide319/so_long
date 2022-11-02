/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:50:08 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/02 10:42:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_read(t_map *map, int fd)
{
	char	*temp;

	map->map = ft_calloc(sizeof(char *), 50);
	temp = get_next_line(fd);
	map->y = 0;
	if (temp == NULL)
	{
		free (temp);
		error(3, map);
	}
	while (temp)
	{
		map->map[map->y] = ft_strdup(temp);
		map->y++;
		if (map->y > 50)
		{
			error(2, map);
		}
		free (temp);
		temp = get_next_line(fd);
	}
	free (temp);
	close (fd);
	if (map->map[0] == NULL || map->map[0][0] == '\n')
		error(3, map);
}

void	map_open(t_map *map, int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc == 2)
	{
		check_file_format(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			error (1, map);
		}
		map_read(map, fd);
	}
	else
	{
		error (1, map);
	}
}
