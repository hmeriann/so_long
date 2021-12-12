/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:50:56 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 19:47:55 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_walls(t_map *map)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (k < map->width && (j == 0 || j == map->width - 1))
	{
		if (map->map[j][k] != '1')
			return (1);
		k++;
	}
	j = 1;
	while (j < map->height - 1)
	{
		if (map->map[j][0] != '1' || map->map[j][map->width - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	ft_validate_map(t_map *map)
{
	if (ft_check_walls(map))
	{
		printf("Error\nMap is not surrounded with walls\n");
		return (1);
	}
	if (ft_check_map_size(map))
		return (1);
	if (ft_count_types(map))
		return (1);
	return (0);
}
