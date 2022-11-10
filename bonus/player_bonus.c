/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:23:13 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/10 13:07:09 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_path(t_vars *vars, int next_y, int next_x)
{
	if (vars->map_2d[next_y][next_x] == WALL)
		return (0);
	if (vars->item_num != 0 && vars->map_2d[next_y][next_x] == EXIT)
		return (0);
	return (1);
}

int	key_hook_input(int key, t_vars *vars, int cur_x, int cur_y)
{
	if (key == UP && is_valid_path(vars, cur_y - 1, cur_x) == 1)
	{
		vars->player.y = cur_y - 1;
		vars->player.dir = 0;
	}
	else if (key == DOWN && is_valid_path(vars, cur_y + 1, cur_x) == 1)
	{
		vars->player.y = cur_y + 1;
		vars->player.dir = 1;
	}
	else if (key == LEFT && is_valid_path(vars, cur_y, cur_x - 1) == 1)
	{
		vars->player.x = cur_x - 1;
		vars->player.dir = 2;
	}
	else if (key == RIGHT && is_valid_path(vars, cur_y, cur_x + 1) == 1)
	{
		vars->player.x = cur_x + 1;
		vars->player.dir = 3;
	}
	else
		return (0);
	return (1);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == ESC)
		exit_game(vars, 0);
	if ((key_hook_input(key, vars, vars->player.x, vars->player.y)) == 0)
		return (0);
	put_movement(vars, ++(vars->movement));
	return (0);
}

int	print_player(t_vars *vars)
{
	char	*str_movement;

	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player.move[vars->player.dir][vars->movement % 2], \
			vars->player.x * 64, vars->player.y * 64);
	str_movement = ft_itoa(vars->movement);
	mlx_string_put(vars->mlx, vars->win, vars->player.x * 64, \
			vars->player.y * 64, 0xFF0000, str_movement);
	free(str_movement);
	event(vars);
	return (0);
}
