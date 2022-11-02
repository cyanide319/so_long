/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:47 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/02 10:43:06 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "include/libft/libft.h"  // to check -bzero
# include "include/printf/ft_printf.h"
# include "include/get_next_line/get_next_line.h"  //------

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
	int		x_top;
	int		x_bot;
	int		x;
	int		fd;

	int		collec;
	int		player;
	int		exit;

	int		ix;
	int		iy;

	int		img_x;
	int		img_y;
	void	*p;
	void	*col;
	void	*e;
	void	*bg;
	void	*walls;
}	t_map;

typedef enum e_bool{
	true,
	false,
}t_bool;

//parse-moi l'sac
void	map_open(t_map *map, int argc, char **argv);
void	map_read(t_map *map, int fd);
char	*ft_get_next_line(int fd);
void	fucking_functions_function(t_map *map);
void	check_top(t_map *map);
void	check_left_side(t_map *map);
void	check_bot(t_map *map);
void	top_x_bottom(t_map *map);
void	check_right_side(t_map *map);
void	check_core(t_map *map);
void	check_components(t_map *map);
void	check_file_format(char *str);
void	valid_comp(char c);

//mlx craps - imgs
void	window_init(t_data *img, t_map *map);
void	get_img(t_data *img, t_map *map);
void	put_img_on_map(t_data *img, t_map *map);
void	img_select(t_data *img, t_map *map, char c);

//errors handling
void	error(int code, t_map *map);
void	free_array(char	***tabp);
void	clean_n_quit(t_map *map);

//key mapping
int		exit_escape(int keycode, t_data *img);
int		exit_x(t_data *img);

#endif