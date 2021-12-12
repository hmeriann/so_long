/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:36:14 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 15:43:14 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	map_init(t_map *map)
{
	map->coll_count = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->height = 0;
	map->map = NULL;
	map->pers_x = 0;
	map->pers_y = 0;
	map->width = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;

	map_init(&map);
	if (!(ft_check_map_type(argc, argv)))
	{
		ft_get_map_width(argv, &map);
		ft_get_map_height(argv, &map);
		ft_get_map(argv, &map);
		if (ft_validate_map(&map))
			exit (1);
		ft_play_the_game(&map);
	}
	exit (0);
}
