/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:14:13 by hyoh              #+#    #+#             */
/*   Updated: 2022/11/07 14:06:05 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*remove_n(char *str)
{
	int	i;

	i = find_n(str);
	if (i != -1)
		str[i] = '\0';
	return (str);
}

int	item_exit_start_check(t_vars *vars)
{
	int	exit_num;
	int	start_num;
	int	y;
	int	x;

	vars->item_num = 0;
	exit_num = 0;
	start_num = 0;
	y = -1;
	while (++y < vars->hei)
	{
		x = -1;
		while (++x < vars->wid)
		{
			if (vars->map_2d[y][x] == ITEM)
				vars->item_num++;
			if (vars->map_2d[y][x] == EXIT)
				exit_num++;
			if (vars->map_2d[y][x] == PLAYER)
				start_num++;
		}
	}
	if (vars->item_num == 0 || exit_num != 1 || start_num != 1)
		return (-1);
	return (1);
}

void	make_2d_array(int y, int x, char *map_1d, t_vars *vars)
{
	vars->map_2d = (char **)malloc(sizeof(char *) * vars->hei);
	if (!vars->map_2d)
		exit_game(vars, MALLOC_FAIL);
	while (++y < vars->hei)
	{
		vars->map_2d[y] = (char *)malloc(sizeof(char) * vars->wid);
		if (!vars->map_2d[y])
		{
			ft_free(y, vars->map_2d);
			exit_game(vars, MALLOC_FAIL);
		}
		x = -1;
		while (++x < vars->wid)
		{
			vars->map_2d[y][x] = *map_1d++;
			if (vars->map_2d[y][x] == PLAYER)
			{
				vars->player.y = y;
				vars->player.x = x;
			}
		}
	}
}

char	*ft_itoa(int num)
{
	char	*str;
	int		len;
	int		temp;

	len = 0;
	temp = num;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len != -1)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

void	put_movement(t_vars *vars, int num)
{
	char	*str;

	str = ft_itoa(num);
	if (!str)
		exit_game(vars, MALLOC_FAIL);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}
