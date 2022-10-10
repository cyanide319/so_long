/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:47 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/10 15:38:18 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	void	*mlx_win;
	void	*mlx;

	char	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		position;
	int		*pixel;
}				t_data;



#endif