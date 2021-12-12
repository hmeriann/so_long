/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:44:31 by zu                #+#    #+#             */
/*   Updated: 2021/12/05 12:15:59 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	link_enemy(t_vars *vars, int width, int height)
{
	vars->enemy.img = mlx_xpm_file_to_image(vars->mlx, ENEMY, \
	&width, &height);
	vars->enemy2.img = mlx_xpm_file_to_image(vars->mlx, ENEMY2, \
	&width, &height);
	vars->enemy3.img = mlx_xpm_file_to_image(vars->mlx, ENEMY3, \
	&width, &height);
	vars->enemy4.img = mlx_xpm_file_to_image(vars->mlx, ENEMY4, \
	&width, &height);
}

static void	link_coll(t_vars *vars, int width, int height)
{
	vars->coll.img = mlx_xpm_file_to_image(vars->mlx, COLL, \
	&width, &height);
	vars->coll2.img = mlx_xpm_file_to_image(vars->mlx, COLL2, \
	&width, &height);
	vars->coll3.img = mlx_xpm_file_to_image(vars->mlx, COLL3, \
	&width, &height);
}

static int	link_images(t_vars *vars)
{
	int	width;
	int	height;

	vars->exit_op.img = mlx_xpm_file_to_image(vars->mlx, \
		EXIT_O, &width, &height);
	vars->exit_cl.img = mlx_xpm_file_to_image(vars->mlx, \
		EXIT_C, &width, &height);
	vars->pers_l.img = mlx_xpm_file_to_image(vars->mlx, \
		PERS_L, &width, &height);
	vars->pers_r.img = mlx_xpm_file_to_image(vars->mlx, \
		PERS_R, &width, &height);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, WALL, \
		&width, &height);
	link_coll(vars, width, height);
	link_enemy(vars, width, height);
	vars->ground.img = mlx_xpm_file_to_image(vars->mlx, GROUND, \
		&width, &height);
	return (0);
}

static void	put_images(t_vars *vars)
{
	int	x;
	int	y;

	vars->i = 0;
	y = 0;
	while (vars->i < vars->height)
	{
		vars->j = 0;
		x = 0;
		while (vars->j < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->ground.img, x, y);
			draw_all(vars, x, y);
			x += TILE_SIZE;
			vars->j++;
		}
		y += TILE_SIZE;
		vars->i++;
	}
}

int	ft_render_map(t_vars *vars)
{
	if (link_images(vars))
	{
		printf("Error\nTexture linking error\n");
		exit (EXIT_FAILURE);
	}
	put_images(vars);
	return (0);
}
