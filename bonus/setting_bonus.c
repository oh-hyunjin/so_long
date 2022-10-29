/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:17:50 by hyoh              #+#    #+#             */
/*   Updated: 2022/10/29 10:48:38 by hyoh             ###   ########.fr       */
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
			exit_game(vars, ERROR_2);
	y = -1;
	while (++y < vars->hei)
		if (vars->map_2d[y][0] != '1' || vars->map_2d[y][vars->wid - 1] != '1')
			exit_game(vars, ERROR_2);
	if (!get_num(vars, 'E') || !get_num(vars, 'C') || get_num(vars, 'P') != 1)
		exit_game(vars, ERROR_3);
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

int	init_vars(char *map_1d, t_vars *vars)
{
	vars->map_2d = make_2d_array(map_1d, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->wid * 64, \
vars->hei * 64, "so_long");
	vars->movement = 0;
	vars->item_num = get_num(vars, ITEM);
	vars->player.dir = 1;
	vars->enemy.dir = 1;
	image_pointer(vars);
	image_pointer_enemy(vars);
	return (0);
}

char	*read_map(char *filename, t_vars *vars)
{
	int		fd;
	char	*temp;
	char	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_game(vars, ERROR_0);
	map = remove_n(get_next_line(fd));
	vars->wid = ft_strlen(map);
	vars->hei = 1;
	while (1)
	{
		temp = remove_n(get_next_line(fd));
		if (temp == NULL)
			break ;
		if (ft_strlen(temp) != vars->wid)
			exit_game(vars, ERROR_1);
		map = ft_strjoin(map, temp);
		free(temp);
		vars->hei++;
	}
	return (map);
}

int	setting(char *filename, t_vars *vars)
{
	char	*map_1d;

	map_1d = read_map(filename, vars);
	init_vars(map_1d, vars);
	map_errorcheck(vars);
	free(map_1d);
	put_enemy(vars);
	return (0);
}
