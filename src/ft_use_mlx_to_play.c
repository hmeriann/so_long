/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_mlx_to_play.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:25 by hmeriann          #+#    #+#             */
/*   Updated: 2021/11/17 15:59:45 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	closewin(void)
{
	exit (EXIT_SUCCESS);
	return (0);
}

static int	link_images(t_vars *vars)
{
	int	width;
	int	height;

	vars->coll.img = mlx_xpm_file_to_image(vars->mlx, COLL, \
		&width, &height);
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
	vars->ground.img = mlx_xpm_file_to_image(vars->mlx, GROUND, \
		&width, &height);
	return (0);
}

void	draw_w_g(t_vars vars, int x, int y)
{
	if (vars.map.map[vars.i][vars.j] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.wall.img, x, y);
	else
		mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.ground.img, x, y);
}

int	ft_render_map(t_vars vars)
{
	int	x;
	int	y;

	if (link_images(&vars))
	{
		printf("Error\nTexture linking error\n");
		exit (EXIT_FAILURE);
	}
	vars.i = 0;
	y = 0;
	while (vars.i < vars.map.height)
	{
		vars.j = 0;
		x = 0;
		while (vars.j < vars.map.width)
		{
			draw_w_g(vars, x, y);
			draw_p_c_e(vars, x, y);
			x += TILE_SIZE;
			vars.j++;
		}
		y += TILE_SIZE;
		vars.i++;
	}
	return (0);
}

void	ft_play_the_game(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * TILE_SIZE, \
	vars.map.height * TILE_SIZE, "so_long");
	ft_render_map(vars);
	vars.map.step_count = 0;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 2, closewin, &vars);
	mlx_loop(vars.mlx);
}
