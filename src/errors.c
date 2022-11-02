/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:37:44 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/01 14:29:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int code, t_map *map)
{
	if (code == 1)
		ft_printf("T'a pas mis d'map, sti d'chaudron\n");
	else if (code == 2)
		ft_printf ("Rentrera pas dans l'ecran esti\n");
	else if (code == 3)
		ft_printf("T'a map est vide dude\n");
	else if (code == 4)
		ft_printf("Ton top top pas comme un top devrais topper\n");
	else if (code == 5)
		ft_printf("Ton bot bot pas comment c'est supposer qu'ça soye\n");
	else if (code == 6)
		ft_printf("Ton top rentre pas dans ton bottom(Pas rectangle)\n");
	else if (code == 7)
		ft_printf("Ton left side suck\n");
	else if (code == 8)
		ft_printf("Ton right side suck\n");
	else if (code == 9)
		ft_printf("S'pas un rectangle ta map, le twit\n");
	else if (code == 10)
		ft_printf("Pas de collectible\n");
	else if (code == 11)
		ft_printf("Un player, pas plus, pas moin\n");
	else if (code == 12)
		ft_printf("Juste une criss de sortie, s'pas dur a comprendre\n");
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
		free_array(&map->map);
	exit (0);
}
