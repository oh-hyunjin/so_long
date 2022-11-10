/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:02:46 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/07 14:06:57 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../lib/src/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define ESC 53

# define ITEM 'C'
# define EXIT 'E'
# define WALL '1'
# define PLAYER 'P'
# define EMPTY '0'

# define WIN 1
# define LOSE 2
# define ERROR_0 3
# define ERROR_1 4
# define ERROR_2 5
# define ERROR_3 6
# define ERROR_4 7
# define MALLOC_FAIL 8

typedef struct s_image
{
	void	*ptr;
	void	*right;
	void	*left;
	void	*move[4][2];
	int		y;
	int		x;
	int		dir;
	int		wid;
	int		hei;
}	t_image;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map_2d;
	int		wid;
	int		hei;
	int		item_num;
	int		movement;
	t_image	player;
	t_image	wall;
	t_image	background;
	t_image	item;
	t_image	exit;
}	t_vars;

typedef struct s_bfs
{
	char	**visit;
	int		dy[4];
	int		dx[4];
	int		exit_flag;
	int		item_flag;
}	t_bfs;

// so_long.c
void	ft_free(int height, char **arr);
int		exit_game(t_vars *vars, int exit_case);
int		ft_loop(t_vars *vars);

// setting.c
int		map_errorcheck(t_vars *vars);
void	image_pointer(t_vars *vars);
int		init_vars(t_vars *vars);
void	read_map(int fd, t_vars *vars);
int		setting(char *filename, t_vars *vars);

// valid_path.c
void	bfs_recur(t_vars *vars, t_bfs *bfs, int cy, int cx);
void	bfs_setting(t_vars *vars, t_bfs *bfs);
int		bfs_check(t_vars *vars);

// player.c
int		is_valid_path(t_vars *vars, int next_y, int next_x);
int		key_hook_input(int key, t_vars *vars, int cur_x, int cur_y);
int		key_hook(int key, t_vars *vars);

// utils.c
char	*remove_n(char *str);
int		item_exit_start_check(t_vars *vars);
void	make_2d_array(int y, int x, char *map_1D, t_vars *vars); // 대문자가능??
char	*ft_itoa(int num);
void	put_movement(t_vars *vars, int num);

#endif
