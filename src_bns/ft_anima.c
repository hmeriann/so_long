/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anima.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:37:05 by zu                #+#    #+#             */
/*   Updated: 2021/12/05 16:39:52 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	frame(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'S')
	{
		if (vars->time < 30)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->enemy.img, x * TILE_SIZE, y * TILE_SIZE);
		else if (vars->time < 60)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->enemy2.img, x * TILE_SIZE, y * TILE_SIZE);
		else if (vars->time < 90)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->enemy3.img, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->enemy4.img, x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	anim_enemy(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			frame(vars, x, y);
			x++;
		}
		y++;
	}
}

static void	frame_coll(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->ground.img, x * TILE_SIZE, y * TILE_SIZE);
		if (vars->time < 40)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->coll.img, x * TILE_SIZE, y * TILE_SIZE);
		else if (vars->time < 80)
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->coll2.img, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->coll3.img, x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	anim_coll(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			frame_coll(vars, x, y);
			x++;
		}
		y++;
	}
}

int	animaciya(t_vars *vars)
{
	ft_patrol(vars);
	ft_re_render_map(vars);
	anim_enemy(vars);
	anim_coll(vars);
	vars->time++;
	if (vars->time == 120)
		vars->time = 0;
	return (0);
}
