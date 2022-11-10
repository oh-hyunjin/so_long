/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:17:50 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/07 12:51:08 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_errorcheck(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->wid == 0 || vars->hei == 0)
		exit_game(vars, ERROR_2);
	x = -1;
	while (++x < vars->wid)
		if (vars->map_2d[0][x] != '1' || vars->map_2d[vars->hei - 1][x] != '1')
			exit_game(vars, ERROR_3);
	y = -1;
	while (++y < vars->hei)
		if (vars->map_2d[y][0] != '1' || vars->map_2d[y][vars->wid - 1] != '1')
			exit_game(vars, ERROR_3);
	if (item_exit_start_check(vars) == -1)
		exit_game(vars, ERROR_1);
	if (bfs_check(vars) == -1)
		exit_game(vars, ERROR_4);
	return (0);
}

void	image_pointer(t_vars *vars)
{
	vars->player.move[0][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_b_0.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[0][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_b_1.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[1][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_r_0.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[1][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_r_1.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[2][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_l_0.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[2][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_l_1.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[3][0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_r_0.xpm", &vars->player.wid, &vars->player.hei);
	vars->player.move[3][1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/nobita_r_1.xpm", &vars->player.wid, &vars->player.hei);
	vars->background.ptr = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/background.xpm", &vars->background.wid, &vars->background.hei);
	vars->wall.ptr = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/tree.xpm", &vars->wall.wid, &vars->wall.hei);
	vars->item.ptr = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/doraemon.xpm", &vars->item.wid, &vars->item.hei);
	vars->exit.ptr = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/anywhere_door.xpm", &vars->exit.wid, &vars->exit.hei);
}

int	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->wid * 64, \
vars->hei * 64, "so_long");
	vars->movement = 0;
	vars->player.dir = 1;
	vars->enemy.dir = 1;
	image_pointer(vars);
	image_pointer_enemy(vars);
	return (0);
}

void	read_map(int fd, t_vars *vars)
{
	char	*temp;
	char	*map;

	map = remove_n(get_next_line(fd));
	if (!map)
		exit_game(vars, ERROR_2);
	vars->wid = ft_strlen(map);
	vars->hei = 1;
	while (1)
	{
		temp = remove_n(get_next_line(fd));
		if (temp == NULL)
			break ;
		if (ft_strlen(temp) != vars->wid)
		{
			free(temp);
			free(map);
			exit_game(vars, ERROR_2);
		}
		map = ft_strjoin(map, temp);
		free(temp);
		vars->hei++;
	}
	make_2d_array(-1, -1, map, vars);
	free(map);
}

int	setting(char *filename, t_vars *vars)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_game(vars, ERROR_0);
	read_map(fd, vars);
	close(fd);
	map_errorcheck(vars);
	init_vars(vars);
	put_enemy(vars);
	return (0);
}
