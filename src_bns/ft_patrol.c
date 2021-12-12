/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patrol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:24:46 by zu                #+#    #+#             */
/*   Updated: 2021/12/05 16:43:37 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	patr_l(t_vars *vars, int x, int y)
{
	vars->map[y][x] = '0';
	vars->map[y][x - 1] = 'S';
}

static void	patr_r(t_vars *vars, int x, int y)
{
	vars->map[y][x] = '0';
	vars->map[y][x + 1] = 'S';
}

int	ft_patrol(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'S' && vars->map[y][x - 1] == '0' \
			&& vars->time * x % 2000 == 0)
				patr_l(vars, x, y);
			if (vars->map[y][x] == 'S' && vars->map[y][x + 1] == '0' \
			&& vars->time * x % 200 == 0)
				patr_r(vars, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
