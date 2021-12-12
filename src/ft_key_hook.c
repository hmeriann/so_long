/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:40:51 by zu                #+#    #+#             */
/*   Updated: 2021/11/16 10:11:53 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_p_c_e(t_vars vars, int x, int y)
{
	if (vars.map.map[vars.i][vars.j] == \
	vars.map.map[vars.map.exit_y][vars.map.exit_x])
	{
		if (vars.map.exit_state == 1)
			mlx_put_image_to_window(vars.mlx, vars.win, \
			vars.exit_op.img, x, y);
		else if (vars.map.exit_state == 0)
			mlx_put_image_to_window(vars.mlx, vars.win, \
			vars.exit_cl.img, x, y);
	}
	else if (vars.map.map[vars.i][vars.j] == 'P')
	{
		if (vars.map.pers_orient == 0)
			mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.pers_r.img, x, y);
		else if (vars.map.pers_orient == 1)
			mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.pers_l.img, x, y);
	}
	else if (vars.map.map[vars.i][vars.j] == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.coll.img, x, y);
	else if (vars.map.map[vars.i][vars.j] == '0')
		mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.ground.img, x, y);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->mlx = vars->mlx;
	if (keycode == 53 || keycode == 256 || keycode == 8)
		exit (0);
	if (keycode == 13)
		ft_move_up(&vars->map);
	if (keycode == 0)
		ft_move_left(&vars->map);
	if (keycode == 1)
		ft_move_down(&vars->map);
	if (keycode == 2)
		ft_move_right(&vars->map);
	ft_render_map(*vars);
	return (0);
}
