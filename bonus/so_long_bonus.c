/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:12:04 by hyoh              #+#    #+#             */
/*   Updated: 2022/10/29 12:04:31 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_game(t_vars *vars, int message)
{
	if (message == 0)
		write(1, "you lose\n", 9);
	else if (message == 1)
		write(1, "you win\n", 8);
	else if (message == ERROR_0)
	{
		write(1, "File open fail\n", 15);
		exit(0);
	}
	else if (message == ERROR_1)
	{
		write(1, "The map must be rectangular\n", 28);
		exit(0);
	}
	else if (message == ERROR_2)
		write(1, "The map must be surrounded by walls\n", 36);
	else if (message == ERROR_3)
		write(1, "Map must have at least one exit, one collectible, \
and one starting position\n", 76);
	else
		write(1, "exit game\n", 10);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	event(t_vars *vars)
{
	if (vars->player.y == vars->enemy.y && vars->player.x == vars->enemy.x)
		exit_game(vars, LOSE);
	else if (vars->map_2d[vars->player.y][vars->player.x] == ITEM)
	{
		vars->item_num--;
		vars->map_2d[vars->player.y][vars->player.x] = '0';
	}
	else if (vars->map_2d[vars->player.y][vars->player.x] == EXIT)
	{
		if (vars->item_num == 0)
			exit_game(vars, WIN);
	}
}

int	ft_loop(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	while (++y < vars->hei)
	{
		x = -1;
		while (++x < vars->wid)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background.ptr, \
				64 * x, 64 * y);
			if (vars->map_2d[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.ptr, \
					x * 64, y * 64);
			else if (vars->map_2d[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->item.ptr, \
					x * 64, y * 64);
			else if (vars->map_2d[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.ptr, \
					x * 64, y * 64);
		}
	}
	print_player(vars);
	move_print_enemy(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		exit_game(0, ERROR_0);
	setting(argv[1], &vars);
	mlx_loop_hook(vars.mlx, ft_loop, &vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &exit_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
