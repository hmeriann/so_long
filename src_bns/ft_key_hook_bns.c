/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:40:51 by zu                #+#    #+#             */
/*   Updated: 2021/12/05 14:40:35 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	draw_exit(t_vars *vars, int x, int y)
{
	if (vars->exit_state == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->exit_op.img, x, y);
	else if (vars->exit_state == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->exit_cl.img, x, y);
}

void	draw_pers(t_vars *vars, int x, int y)
{
	if (vars->pers_orient == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->pers_r.img, x, y);
	else if (vars->pers_orient == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->pers_l.img, x, y);
}

void	draw_all(t_vars *vars, int x, int y)
{
	if (vars->map[vars->i][vars->j] == 'P')
		draw_pers(vars, x, y);
	else if (vars->map[vars->i][vars->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->wall.img, x, y);
	else if (vars->map[vars->i][vars->j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->coll.img, x, y);
	else if (vars->map[vars->i][vars->j] == 'E')
		draw_exit(vars, x, y);
	else if (vars->map[vars->i][vars->j] == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->enemy.img, x, y);
}

void	draw_w_g(t_vars *vars, int x, int y)
{
	if (vars->map[vars->i][vars->j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->wall.img, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->ground.img, x, y);
	if (vars->map[vars->i][vars->j] == \
	vars->map[vars->exit_y][vars->exit_x])
		draw_exit(vars, x, y);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 256 || keycode == 8)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13)
		ft_move_up(vars);
	else if (keycode == 0)
		ft_move_left(vars);
	else if (keycode == 1)
		ft_move_down(vars);
	else if (keycode == 2)
		ft_move_right(vars);
	return (0);
}
