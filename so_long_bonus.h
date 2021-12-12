/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:35:29 by zu                #+#    #+#             */
/*   Updated: 2021/12/05 17:08:48 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define MLX_ERROR	1
# define COLL		"assets/coll.xpm"
# define COLL2		"assets/coll2.xpm"
# define COLL3		"assets/coll3.xpm"
# define PERS_L		"assets/pers_l.xpm"
# define PERS_R		"assets/pers_r.xpm"
# define EXIT_O		"assets/exit_o.xpm"
# define EXIT_C		"assets/exit.xpm"
# define WALL		"assets/wall.xpm"
# define GROUND		"assets/ground.xpm"
# define ENEMY		"assets/enemy.xpm"
# define ENEMY2		"assets/enemy2.xpm"
# define ENEMY3		"assets/enemy3.xpm"
# define ENEMY4		"assets/enemy4.xpm"
# define TILE_SIZE	75

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		pers_x;
	int		pers_y;
	int		exit_x;
	int		exit_y;
	int		coll_count;
}	t_map;

typedef struct s_types {
	int	start;
	int	wall;
	int	space;
	int	exit;
	int	collectbl;
	int	enemy;
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
	char	**map;
	t_asset	wall;
	t_asset	coll;
	t_asset	coll2;
	t_asset	coll3;
	t_asset	pers_l;
	t_asset	pers_r;
	t_asset	exit_cl;
	t_asset	exit_op;
	t_asset	ground;
	t_asset	enemy;
	t_asset	enemy2;
	t_asset	enemy3;
	t_asset	enemy4;
	int		i;
	int		j;
	void	*image;
	int		frame;
	int		width;
	int		height;
	int		time;
	int		flag;
	int		exit_state;
	int		step_count;
	int		pers_orient;
	int		pers_x;
	int		pers_y;
	int		exit_x;
	int		exit_y;
	int		coll_count;
}	t_vars;

char	*ft_strnstr(char *haystack, const char *needle, size_t len);
int		ft_check_map_type(int argc, char **argv);
void	ft_get_map_width(char **argv, t_map *map);
void	ft_get_map_height(char **argv, t_map *map);
void	ft_get_map(char **argv, t_map *map);
int		ft_check_walls(t_map *map);
int		ft_validate_map(t_map *map);
int		ft_count_types(t_map *map);
int		ft_check_map_size(t_map *map);
void	ft_check_rectang(char *line, t_map *map);
void	vars_init(t_map	*map, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		ft_play_the_game(t_map *map);
void	decrease_count(t_vars *vars);
void	draw_exit(t_vars *vars, int x, int y);
void	draw_pers(t_vars *vars, int x, int y);
void	draw_w_g(t_vars *vars, int x, int y);
void	draw_all(t_vars *vars, int x, int y);
int		ft_render_map(t_vars *vars);
void	ft_move_up(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_right(t_vars *vars);
int		ft_re_render_map(t_vars *vars);
char	*ft_make_message(t_vars *vars);
int		ft_patrol(t_vars *vars);
int		animaciya(t_vars *vars);

#endif
