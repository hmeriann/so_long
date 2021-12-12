/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_mlx_bns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:25 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/12 15:36:09 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	closewin(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

void	vars_init(t_map	*map, t_vars *vars)
{
	vars->map = map->map;
	vars->pers_x = map->pers_x;
	vars->pers_y = map->pers_y;
	vars->coll_count = map->coll_count;
	vars->exit_x = map->exit_x;
	vars->exit_y = map->exit_y;
	vars->height = map->height;
	vars->width = map->width;
	vars->pers_orient = 0;
	vars->exit_state = 0;
	vars->time = 0;
	vars->frame = 0;
	vars->step_count = 0;
	vars->i = 0;
	vars->j = 0;
}

int	ft_play_the_game(t_map *map)
{
	t_vars	vars;
	char	*str;

	vars_init(map, &vars);
	vars.mlx = mlx_init();
	if (vars.mlx == 0)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, vars.width * TILE_SIZE, \
	vars.height * TILE_SIZE, "so_long");
	if (!vars.win)
	{
		free(vars.win);
		return (MLX_ERROR);
	}
	ft_render_map(&vars);
	str = ft_make_message(&vars);
	mlx_string_put(vars.mlx, vars.win, 25, 25, 0x00007FFF, str);
	free(str);
	mlx_loop_hook(vars.mlx, animaciya, &vars);
	mlx_hook(vars.win, 2, 0L, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 2, closewin, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
