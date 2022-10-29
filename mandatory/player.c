/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:55:26 by hyoh              #+#    #+#             */
/*   Updated: 2022/10/28 09:35:43 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	pre_y;
	int	pre_x;

	if (key == ESC)
		exit_game(vars, -1);
	pre_x = vars->player.x;
	pre_y = vars->player.y;
	if ((key_hook_input(key, vars, vars->player.x, vars->player.y)) == 0)
		return (0);
	if (vars->map_2d[vars->player.y][vars->player.x] == ITEM)
	{
		vars->item_num--;
		vars->map_2d[vars->player.y][vars->player.x] = '0';
	}
	else if (vars->map_2d[vars->player.y][vars->player.x] == EXIT && \
vars->item_num == 0)
		exit_game(vars, WIN);
	put_movement(++(vars->movement));
	return (0);
}

int	is_valid_path(t_vars *vars, int next_y, int next_x)
{
	if (vars->map_2d[next_y][next_x] == WALL)
		return (0);
	if (vars->item_num != 0 && vars->map_2d[next_y][next_x] == EXIT)
		return (0);
	return (1);
}
