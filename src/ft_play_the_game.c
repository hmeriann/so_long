/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_the_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:37:08 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 13:50:53 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_up(t_map *map)
{
	if (map->map[map->pers_y - 1][map->pers_x] != '1')
	{
		if (map->map[map->pers_y - 1][map->pers_x] == 'E' && \
		map->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (map->map[map->pers_y - 1][map->pers_x] == 'E' && \
		map->coll_count)
			map->pers_y = map->pers_y;
		else
		{
			if (map->map[map->pers_y - 1][map->pers_x] == 'C')
				decrease_count(map);
			map->map[map->pers_y - 1][map->pers_x] = 'P';
			map->map[map->pers_y][map->pers_x] = '0';
			map->pers_y = map->pers_y - 1;
			map->step_count += 1;
			printf("Player made steps count is < %d >\n", map->step_count);
		}
	}
	else
		return ;
}

void	ft_move_down(t_map *map)
{
	if (map->map[map->pers_y + 1][map->pers_x] != '1')
	{
		if (map->map[map->pers_y + 1][map->pers_x] == 'E' && \
		map->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (map->map[map->pers_y + 1][map->pers_x] == 'E' && \
		map->coll_count)
			map->pers_y = map->pers_y;
		else
		{
			if (map->map[map->pers_y + 1][map->pers_x] == 'C')
				decrease_count(map);
			map->map[map->pers_y + 1][map->pers_x] = 'P';
			map->map[map->pers_y][map->pers_x] = '0';
			map->pers_y = map->pers_y + 1;
			map->step_count += 1;
			printf("Player made steps count is < %d >\n", map->step_count);
		}
	}
	else
		return ;
}

void	ft_move_left(t_map *map)
{
	if (map->map[map->pers_y][map->pers_x - 1] != '1')
	{
		if (map->map[map->pers_y][map->pers_x - 1] == 'E' && \
		map->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (map->map[map->pers_y][map->pers_x - 1] == 'E' && \
		map->coll_count)
			map->pers_x = map->pers_x;
		else
		{
			if (map->map[map->pers_y][map->pers_x - 1] == 'C')
				decrease_count(map);
			map->map[map->pers_y][map->pers_x - 1] = 'P';
			map->map[map->pers_y][map->pers_x] = '0';
			map->pers_x = map->pers_x - 1;
			map->step_count += 1;
			map->pers_orient = 1;
			printf("Player made steps count is < %d >\n", map->step_count);
		}
	}
	else
		return ;
}

void	ft_move_right(t_map *map)
{
	if (map->map[map->pers_y][map->pers_x + 1] != '1')
	{
		if (map->map[map->pers_y][map->pers_x + 1] == 'E' && \
		map->coll_count == 0)
		{
			printf("Congratulations: >>* You won! *<<\n");
			exit (EXIT_SUCCESS);
		}
		else if (map->map[map->pers_y][map->pers_x + 1] == 'E' && \
		map->coll_count)
			map->pers_x = map->pers_x;
		else
		{
			if (map->map[map->pers_y][map->pers_x + 1] == 'C')
				decrease_count(map);
			map->map[map->pers_y][map->pers_x + 1] = 'P';
			map->map[map->pers_y][map->pers_x] = '0';
			map->pers_x = map->pers_x + 1;
			map->pers_orient = 0;
			map->step_count += 1;
			printf("Player made steps count is < %d >\n", map->step_count);
		}
	}
	else
		return ;
}
