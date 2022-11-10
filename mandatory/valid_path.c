/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:49:03 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/10 10:48:23 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bfs_recur(t_vars *vars, t_bfs *bfs, int cy, int cx)
{
	int	i;
	int	ny;
	int	nx;

	i = -1;
	while (++i < 4)
	{
		ny = cy + bfs->dy[i];
		nx = cx + bfs->dx[i];
		if (vars->map_2d[ny][nx] == WALL)
			continue ;
		if (bfs->visit[ny][nx] == 1)
			continue ;
		if (vars->map_2d[ny][nx] == EXIT)
		{
			bfs->exit_flag = 1;
			continue ;
		}
		if (vars->map_2d[ny][nx] == ITEM)
			bfs->item_flag++;
		bfs->visit[ny][nx] = 1;
		bfs_recur(vars, bfs, ny, nx);
	}
}

void	bfs_setting(t_vars *vars, t_bfs *bfs)
{
	int		y;
	int		x;

	bfs->visit = (char **)malloc(sizeof(char *) * vars->hei);
	if (!bfs->visit)
		exit_game(vars, MALLOC_FAIL);
	y = -1;
	while (++y < vars->hei)
	{
		bfs->visit[y] = (char *)malloc(sizeof(char) * vars->wid);
		if (!bfs->visit[y])
		{
			ft_free(y, bfs->visit);
			exit_game(vars, MALLOC_FAIL);
		}
		x = -1;
		while (++x < vars->wid)
			bfs->visit[y][x] = 0;
	}
	bfs->exit_flag = 0;
	bfs->item_flag = 0;
}

int	bfs_check(t_vars *vars)
{
	t_bfs	bfs;

	bfs.dy[0] = -1;
	bfs.dy[1] = 0;
	bfs.dy[2] = 0;
	bfs.dy[3] = 1;
	bfs.dx[0] = 0;
	bfs.dx[1] = -1;
	bfs.dx[2] = 1;
	bfs.dx[3] = 0;
	bfs_setting(vars, &bfs);
	bfs_recur(vars, &bfs, vars->player.y, vars->player.x);
	ft_free(vars->hei, bfs.visit);
	if (bfs.exit_flag == 1 && bfs.item_flag == vars->item_num)
		return (1);
	return (-1);
}
