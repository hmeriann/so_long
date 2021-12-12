/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:18:40 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 15:38:34 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	move_r(t_vars *vars)
{
	char	*str;

	if (vars->map[vars->pers_y][vars->pers_x + 1] == 'C')
		decrease_count(vars);
	vars->map[vars->pers_y][vars->pers_x + 1] = 'P';
	vars->map[vars->pers_y][vars->pers_x] = '0';
	vars->pers_x = vars->pers_x + 1;
	vars->pers_orient = 0;
	vars->step_count += 1;
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->ground.img, vars->pers_x, vars->pers_y);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 0, 75);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 0, 75 * 2);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 75, 0);
	str = ft_make_message(vars);
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0x00007FFF, str);
	free(str);
}

static void	move_l(t_vars *vars)
{
	char	*str;

	if (vars->map[vars->pers_y][vars->pers_x - 1] == 'C')
		decrease_count(vars);
	vars->map[vars->pers_y][vars->pers_x - 1] = 'P';
	vars->map[vars->pers_y][vars->pers_x] = '0';
	vars->pers_x = vars->pers_x - 1;
	vars->step_count += 1;
	vars->pers_orient = 1;
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->ground.img, vars->pers_x, vars->pers_y);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 0, 75);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 0, 75 * 2);
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->wall.img, 75, 0);
	str = ft_make_message(vars);
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0x00007FFF, str);
	free(str);
}

void	ft_move_left(t_vars *vars)
{
	if (vars->map[vars->pers_y][vars->pers_x - 1] != '1')
	{
		if (vars->map[vars->pers_y][vars->pers_x - 1] == 'E' && \
		vars->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (vars->map[vars->pers_y][vars->pers_x - 1] == 'E' && \
		vars->coll_count)
			vars->pers_x = vars->pers_x;
		else if (vars->map[vars->pers_y][vars->pers_x - 1] == 'S')
		{
			printf("<<* You've lost! *>>\n");
			exit (EXIT_SUCCESS);
		}
		else
			move_l(vars);
	}
	else
	{
		return ;
	}
}

void	ft_move_right(t_vars *vars)
{
	if (vars->map[vars->pers_y][vars->pers_x + 1] != '1')
	{
		if (vars->map[vars->pers_y][vars->pers_x + 1] == 'E' && \
		vars->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (vars->map[vars->pers_y][vars->pers_x + 1] == 'E' && \
		vars->coll_count)
			vars->pers_x = vars->pers_x;
		else if (vars->map[vars->pers_y][vars->pers_x + 1] == 'S')
		{
			printf("<<* You've lost! *>>\n");
			exit (EXIT_SUCCESS);
		}
		else
			move_r(vars);
	}
	else
		return ;
}
