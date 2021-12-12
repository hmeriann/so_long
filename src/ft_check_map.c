/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:55:12 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/12 15:41:04 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	save_tyle(t_map *map, t_types *types, int i, int j)
{
	if (map->map[j][i] == '1')
		types->wall += 1;
	else if (map->map[j][i] == '0')
		types->space += 1;
	else if (map->map[j][i] == 'E')
	{
		types->exit += 1;
		map->exit_x = i;
		map->exit_y = j;
	}
	else if (map->map[j][i] == 'P')
	{
		types->start += 1;
		map->pers_x = i;
		map->pers_y = j;
	}
	else if (map->map[j][i] == 'C')
	{
		types->collectbl += 1;
		map->coll_count += 1;
	}
}

static int	parce_types(t_map *map, t_types	*types)
{
	int		i;
	int		j;

	j = 0;
	map->coll_count = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (!ft_strchr("EPC01", map->map[j][i]))
				return (1);
			else
				save_tyle(map, types, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_count_types(t_map *map)
{
	t_types	*types;

	types = (t_types *)calloc(1, sizeof(t_types));
	if (parce_types(map, types))
	{
		printf("Error\nInvalid tyles\n");
		free(types);
		return (1);
	}
	if (types->collectbl < 1 || types->start != 1 || types->exit < 1 || \
	types->exit < 1 || types->wall < 0)
	{
		printf("Error\nToo many players or there is no other types of tyles\n");
		free(types);
		return (1);
	}
	else
	{
		free(types);
		return (0);
	}
}

int	ft_check_map_size(t_map *map)
{
	if (map->width > 15 || map->height > 15)
	{
		printf("Error\nMap dimentions should be less than 15x15\n");
		return (1);
	}
	if (map->width < 3 || map->height < 3)
	{
		printf("Error\nMap dimentions should be more than 2x2\n");
		return (1);
	}
	else
		return (0);
}

void	decrease_count(t_map *map)
{
	map->coll_count--;
	if (map->coll_count == 0)
		map->exit_state = 1;
}
