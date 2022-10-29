/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:02:46 by hyoh              #+#    #+#             */
/*   Updated: 2022/10/29 12:01:35 by hyoh             ###   ########.fr       */
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

# define LOSE 0
# define WIN 1
# define ERROR_0 2
# define ERROR_1 3
# define ERROR_2 4
# define ERROR_3 5

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

int		get_num(t_vars *vars, char target);
char	*remove_n(char *str);
char	**make_into_2d(char *map_1D, t_vars *vars);
char	*ft_itoa(int num);
void	put_movement(int num);
int		setting(char *filename, t_vars *vars);
char	*read_map(char *filename, t_vars *vars);
int		map_errorcheck(t_vars *vars);
int		init_vars(char *map_1D, t_vars *vars);
void	image_pointer(t_vars *vars);
int		ft_loop(t_vars *vars);
int		print_map(t_vars *vars);
int		exit_game(t_vars *vars, int message);
int		main(int argc, char **argv);
int		key_hook(int key, t_vars *vars);
int		key_hook_input(int key, t_vars *vars, int cur_x, int cur_y);
int		print_player(t_vars *vars);
int		is_valid_path(t_vars *vars, int next_y, int next_x);

#endif
