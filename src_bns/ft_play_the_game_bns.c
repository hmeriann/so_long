/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_the_game_bns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:37:08 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 15:37:47 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	decrease_count(t_vars *vars)
{
	vars->coll_count--;
	if (vars->coll_count == 0)
		vars->exit_state = 1;
}

static void	move_u(t_vars *vars)
{
	char	*str;

	if (vars->map[vars->pers_y - 1][vars->pers_x] == 'C')
		decrease_count(vars);
	vars->map[vars->pers_y - 1][vars->pers_x] = 'P';
	vars->map[vars->pers_y][vars->pers_x] = '0';
	vars->pers_y = vars->pers_y - 1;
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

static void	move_d(t_vars *vars)
{
	char	*str;

	if (vars->map[vars->pers_y + 1][vars->pers_x] == 'C')
		decrease_count(vars);
	vars->map[vars->pers_y + 1][vars->pers_x] = 'P';
	vars->map[vars->pers_y][vars->pers_x] = '0';
	vars->pers_y = vars->pers_y + 1;
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

void	ft_move_up(t_vars *vars)
{
	if (vars->map[vars->pers_y - 1][vars->pers_x] != '1')
	{
		if (vars->map[vars->pers_y - 1][vars->pers_x] == 'E' && \
		vars->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (vars->map[vars->pers_y - 1][vars->pers_x] == 'E' && \
		vars->coll_count)
			vars->pers_y = vars->pers_y;
		else if (vars->map[vars->pers_y - 1][vars->pers_x] == 'S')
		{
			printf("<<* You've lost! *>>\n");
			exit (EXIT_SUCCESS);
		}
		else
			move_u(vars);
	}
	else
		return ;
}

void	ft_move_down(t_vars *vars)
{
	if (vars->map[vars->pers_y + 1][vars->pers_x] != '1')
	{
		if (vars->map[vars->pers_y + 1][vars->pers_x] == 'E' && \
		vars->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (vars->map[vars->pers_y + 1][vars->pers_x] == 'E' && \
		vars->coll_count)
			vars->pers_y = vars->pers_y;
		else if (vars->map[vars->pers_y + 1][vars->pers_x] == 'S')
		{
			printf("<<* You've lost! *>>\n");
			exit (EXIT_SUCCESS);
		}
		else
			move_d(vars);
	}
	else
		return ;
}
