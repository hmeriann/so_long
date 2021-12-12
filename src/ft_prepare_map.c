/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:36:49 by zu                #+#    #+#             */
/*   Updated: 2021/12/12 14:34:10 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_map_type(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Pass the map as parameter\n");
		return (1);
	}
	else if (ft_strnstr(argv[1], "ber", 3))
	{
		printf("Your map is not .ber\n");
		return (1);
	}
	else
		return (0);
}

void	ft_check_rectang(char *line, t_map *map)
{
	if (map->width != (int)ft_strlen(line))
	{
		ft_putstr_fd("Error\nMap isn't rectangular\n", 1);
		exit(1);
	}
}

void	ft_get_map_width(char **argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("open() is failed\n", 1);
		exit (EXIT_FAILURE);
	}
	get_next_line(fd, &line);
	map->width = ft_strlen(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		ft_check_rectang(line, map);
		free(line);
	}
	if (map->width != (int)ft_strlen(line))
	{
		ft_putstr_fd("Error\nMap isn't rectangular\n", 1);
		exit(1);
	}
	free(line);
	close(fd);
}

void	ft_get_map_height(char **argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("open() is failed\n", 1);
		exit (EXIT_FAILURE);
	}
	map->height = 1;
	while (get_next_line(fd, &line))
	{
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
}

void	ft_get_map(char **argv, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->map = (char **)malloc(sizeof (char *) * (map->height + 1));
	i = 0;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd < 0)
	{
		ft_putstr_fd("open() is failed\n", 1);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		map->map[i] = line;
		i++;
	}
	map->map[i] = line;
	i++;
	map->map[i] = NULL;
	close(fd);
}
