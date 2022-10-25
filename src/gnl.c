/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:56:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/11 17:57:14 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_get_next_line(int fd)
{
	char	*str;
	char	*buff;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 5);
	buff = str;
	while (read(fd, buff, 1) > 0 && *buff++ != '\n')
		i++;
	if (buff > str)
	{
		buff = 0;
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}
