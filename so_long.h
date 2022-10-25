/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:47 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/25 18:39:27 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "include/libft/libft.h"
# include "include/printf/ft_printf.h"
# include "include/get_next_line/get_next_line.h"

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

typedef struct s_map{
	char	**map;
	int		y;
	int		x;
	int		fd;
}	t_map;

typedef enum e_bool{
	true,
	false,
}t_bool;

//parse-moi l'sac
void	map_open(t_map *map);
char	*ft_get_next_line(int fd);

//errors handling
void	error(int code, t_map *map);
void	free_array(char	***tabp);
void	clean_n_quit(t_map *map);

//key maps
int		exit_escape(int keycode, t_data *img, t_map *map);
int		exit_x(t_data *img, t_map *map);

#endif