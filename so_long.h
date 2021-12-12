/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:35:29 by zu                #+#    #+#             */
/*   Updated: 2021/12/05 16:57:11 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define COLL "assets/coll.xpm"
# define PERS_L "assets/pers_l.xpm"
# define PERS_R "assets/pers_r.xpm"
# define EXIT_O "assets/exit_o.xpm"
# define EXIT_C "assets/exit.xpm"
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define TILE_SIZE 75

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		pers_x;
	int		pers_y;
	int		pers_orient;
	int		exit_x;
	int		exit_y;
	int		exit_state;
	int		coll_count;
	int		step_count;
}	t_map;

typedef struct s_types {
	int	start;
	int	wall;
	int	space;
	int	exit;
	int	collectbl;
}	t_types;

typedef struct s_asset {
	void	*img;
	int		img_width;
	int		img_height;
}	t_asset;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_asset	wall;
	t_asset	coll;
	t_asset	pers_l;
	t_asset	pers_r;
	t_asset	exit_cl;
	t_asset	exit_op;
	t_asset	ground;
	int		i;
	int		j;
}	t_vars;

char	*ft_strnstr(char *haystack, const char *needle, size_t len);
int		ft_check_map_type(int argc, char **argv);
void	ft_check_rectang(char *line, t_map *map);
void	ft_get_map_width(char **argv, t_map *map);
void	ft_get_map_height(char **argv, t_map *map);
void	ft_get_map(char **argv, t_map *map);
int		ft_check_walls(t_map *map);
int		ft_validate_map(t_map *map);
int		ft_count_types(t_map *map);
int		ft_check_map_size(t_map *map);
int		key_hook(int keycode, t_vars *vars);
void	ft_play_the_game(t_vars vars);
void	draw_p_c_e(t_vars vars, int x, int y);
void	draw_w_g(t_vars vars, int x, int y);
int		ft_render_map(t_vars vars);
void	decrease_count(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_right(t_map *map);
int		ft_re_render_map(t_vars vars);

#endif
