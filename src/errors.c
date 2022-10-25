/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:37:44 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/25 18:38:46 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int code, t_map *map)
{
	if (code == 1)
	{
		ft_printf("T'a pas mis d'map, sti d'chaudron\n");
	}
	else if (code == 2)
	{
		ft_printf ("Rentrera pas dans l'ecran esti\n");
	}
	else if (code == 3)
	{
		ft_printf("T'a map est vide dude\n");
	}
	clean_n_quit(map);
}

void	free_array(char	***tabp)
{
	int		i;
	char	**tab;

	i = 0;
	tab = *tabp;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
	*tabp = NULL;
}

void	clean_n_quit(t_map *map)
{
	if (map->map)
		free(map->map);
	if (map->fd != -1 && map->fd != 0)
		close (map->fd);
	exit (0);
}