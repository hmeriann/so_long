/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:36:14 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 14:47:25 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.map.pers_orient = 0;
	vars.map.exit_state = 0;
	if (!(ft_check_map_type(argc, argv)))
	{
		ft_get_map_width(argv, &vars.map);
		ft_get_map_height(argv, &vars.map);
		ft_get_map(argv, &vars.map);
		if (ft_validate_map(&vars.map))
			exit (1);
		ft_play_the_game(vars);
	}
	exit (0);
}
