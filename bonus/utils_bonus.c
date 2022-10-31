/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:14:13 by hyoh              #+#    #+#             */
/*   Updated: 2022/10/31 11:07:35 by hyoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*remove_n(char *str)
{
	int	i;

	i = find_n(str);
	if (i != -1)
		str[i] = '\0';
	return (str);
}

int	get_num(t_vars *vars, char target)
{
	int	n;
	int	y;
	int	x;

	n = 0;
	y = -1;
	while (++y < vars->hei)
	{
		x = -1;
		while (++x < vars->wid)
		{
			if (vars->map_2d[y][x] == target)
				n++;
		}
	}
	return (n);
}

char	**make_2d_array(char *map_1d, t_vars *vars)
{
	char	**result;
	int		y;
	int		x;

	result = (char **)malloc(sizeof(char *) * vars->hei);
	if (result == NULL)
		return (NULL);
	y = -1;
	while (++y < vars->hei)
	{
		result[y] = (char *)malloc(sizeof(char) * vars->wid);
		if (result[y] == NULL)
			return (NULL);
		x = -1;
		while (++x < vars->wid)
		{
			result[y][x] = *map_1d++;
			if (result[y][x] == PLAYER)
			{
				vars->player.y = y;
				vars->player.x = x;
			}
		}
	}
	return (result);
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
		return (0);
	str[len] = '\0';
	while (--len != -1)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

void	put_movement(int num)
{
	char	*str;

	str = ft_itoa(num);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}
