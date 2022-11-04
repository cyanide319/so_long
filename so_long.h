/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:29:47 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/04 13:57:43 by tbeaudoi         ###   ########.fr       */
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
	int		exitcheck;

	int		modeflag;
	int		clock;
	int		xflag;

	int		ix;
	int		iy;
	int		px;
	int		py;
	int		mv;
	int		ex;
	int		ey;

	int		img_x;
	int		img_y;

	void	*p;
	void	*p2;
	void	*col;
	void	*col2;
	void	*e;
	void	*e2;
	void	*bg;
	void	*bg2;
	void	*walls;
	void	*walls2;
	void	*x_current;
	void	*x_l;
	void	*x_r;
	void	*x_u;
	void	*x_d;

	void	*img;
	void	*mlx_win;
	void	*mlx;
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
void	check_valid_path(t_map *map);
t_bool	check_img_file(char *str);

//mlx craps - imgs
void	window_init(t_map *map);
void	get_img(t_map *map);
void	get_img2(t_map *map);
void	put_img_on_map(t_map *map);
void	img_select(t_map *map, char c);
int		update(t_map *map);

//errors handling
void	error(int code, t_map *map);
void	free_array(char	***tabp);
void	clean_n_quit(t_map *map);

//player moves
void	find_player_pos(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	win_game(t_map *map);
void	lose_game(t_map *map);

//enemy moves
void	find_enemy_pos(t_map *map);
void	enemy_moves(t_map *map, int mv_flag);
void	e_move_right(t_map *map);
void	e_move_left(t_map *map);
void	e_move_up(t_map *map);
void	e_move_down(t_map *map);
void	enemy_ctrl(t_map *map);

//key mapping
int		exit_escape(int keycode, t_map *map);
int		exit_x(t_map *map);
int		keybinds(int keycode, t_map *map);

//chaos
void	swap_p_x(t_map *map);
void	swap_wall(t_map *map);

#endif