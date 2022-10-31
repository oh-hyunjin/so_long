/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:56:02 by hyoh              #+#    #+#             */
/*   Updated: 2022/10/31 10:36:32 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_pointer_enemy(t_vars *vars)
{
	vars->enemy.move[0][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_b_0.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[0][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_b_1.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[1][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_r_0.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[1][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_r_1.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[2][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_l_0.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[2][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_l_1.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[3][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_r_0.xpm", &vars->enemy.wid, &vars->exit.hei);
	vars->enemy.move[3][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/toong_r_1.xpm", &vars->enemy.wid, &vars->exit.hei);
}

void	put_enemy(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < vars->hei)
		while (++x < vars->wid)
			if (vars->map_2d[y][x] == '0')
				break ;
	if (y == vars->hei && x == vars->wid)
		return ;
	srand((unsigned int)time(NULL));
	while (1)
	{
		y = rand() % vars->hei;
		x = rand() % vars->wid;
		if (vars->map_2d[y][x] == '0')
			break ;
	}
	vars->enemy.y = y;
	vars->enemy.x = x;
}

void	move_enemy(t_vars *vars, int curY, int curX)
{
	int	dir;

	while (1)
	{
		dir = rand() % 4;
		if (dir == 0 && vars->map_2d[curY - 1][curX] == '0')
			vars->enemy.y = curY - 1;
		else if (dir == 1 && vars->map_2d[curY + 1][curX] == '0')
			vars->enemy.y = curY + 1;
		else if (dir == 2 && vars->map_2d[curY][curX - 1] == '0')
			vars->enemy.x = curX - 1;
		else if (dir == 3 && vars->map_2d[curY][curX + 1] == '0')
			vars->enemy.x = curX + 1;
		else
			continue ;
		break ;
	}
	vars->enemy.dir = dir;
}

void	move_print_enemy(t_vars *vars)
{
	static int	n_movement;
	static int	speed = 0;

	speed++;
	if (speed % 40 == 0)
	{
		move_enemy(vars, vars->enemy.y, vars->enemy.x);
		n_movement++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->enemy.move[vars->enemy.dir][n_movement % 2], \
			vars->enemy.x * 64, vars->enemy.y * 64);
}
