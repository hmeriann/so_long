/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_render_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:16:11 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 15:36:47 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	re_draw(t_vars *vars, int x, int y)
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
	if (vars->map[vars->i][vars->j] == \
	vars->map[vars->pers_y][vars->pers_x])
		draw_pers(vars, x, y);
}

int	ft_re_render_map(t_vars *vars)
{
	int		x;
	int		y;
	char	*str;

	vars->i = 0;
	y = 0;
	while (vars->i < vars->height)
	{
		vars->j = 0;
		x = 0;
		while (vars->j < vars->width)
		{
			re_draw(vars, x, y);
			x += TILE_SIZE;
			vars->j++;
		}
		y += TILE_SIZE;
		vars->i++;
	}
	str = ft_make_message(vars);
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0x00007FFF, str);
	free(str);
	return (0);
}
