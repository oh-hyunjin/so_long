/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:12:04 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/10 10:47:50 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(int height, char **arr)
{
	int	i;

	i = 0;
	while (i < height)
		free(arr[i++]);
	free(arr);
}

int	exit_game(t_vars *vars, int exit_case)
{
	if (exit_case == ERROR_0)
		write(1, "Error\nFile open fail\n", 21);
	else if (exit_case == ERROR_1)
		write(1, "Error\nThe map must contain 1 exit, at least 1 collectible, \
and 1 starting position\n", 83);
	else if (exit_case == ERROR_2)
		write(1, "Error\nThe map must be rectangular\n", 34);
	else if (exit_case == ERROR_3)
		write(1, "Error\nThe map must be surrounded by walls\n", 42);
	else if (exit_case == ERROR_4)
		write(1, "Error\nThe map must have a valid path\n", 37);
	else if (exit_case == MALLOC_FAIL)
		write(1, "malloc fail\n", 12);
	else if (exit_case == WIN)
		write(1, "you win\n", 8);
	else if (exit_case == LOSE)
		write(1, "you lose\n", 9);
	else
		write(1, "exit game\n", 10);
	if (vars->map_2d != NULL)
		ft_free(vars->hei, vars->map_2d);
	if (vars->mlx != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.move[vars->\
player.dir][vars->movement % 2], vars->player.x * 64, vars->player.y * 64);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.mlx = NULL;
	vars.map_2d = NULL;
	if (argc != 2)
		exit_game(&vars, ERROR_0);
	setting(argv[1], &vars);
	mlx_loop_hook(vars.mlx, ft_loop, &vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, &exit_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
